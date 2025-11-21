#include "FilaDeProcessos.h"
// DICA DE PROVA: INCLUDE HELL
// Por que incluir tudo isso aqui?
// Porque no método "carregarDeArquivo", nós damos "new ComputingProcess", "new WritingProcess"...
// Se não incluirmos os .h deles, o compilador não sabe como criar esses objetos.
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include <iostream>

using namespace std;

// Inicializa a fila vazia (ponteiros nulos).
FilaDeProcessos::FilaDeProcessos() : comeco(nullptr), fim(nullptr) {};

FilaDeProcessos::~FilaDeProcessos() {};

// --- DICA DE PROVA: ADICIONAR NO FIM (O(1)) ---
void FilaDeProcessos::adicionar(Processo* p) {
	Node* novoNode = new Node(p); // Cria o vagão

	if (comeco == nullptr) {
		// Cenário 1: Fila Vazia
		// O novo nó é o primeiro E o último ao mesmo tempo.
		comeco = novoNode;
		fim = novoNode;
	}
	else {
		// Cenário 2: Já tem gente
		// 1. O atual último (fim) dá a mão para o novo (fim->proximo = novo)
		fim->proximo = novoNode;
		// 2. Atualizamos a placa de "Fim" para o novo nó
		fim = novoNode;
	}
};

// --- DICA DE PROVA: REMOVER DO INÍCIO ---
void FilaDeProcessos::executarProx() {
	if (comeco == nullptr) {
		cout << "Fila Vazia!" << endl;
		return;
	}

	// 1. Salva o nó que vai morrer (temp)
	Node* temp = comeco;

	// 2. Executa a ação (Polimorfismo: cada filho age de um jeito)
	temp->processo->execute();

	// 3. Move o começo da fila para o segundo da lista
	comeco = comeco->proximo;

	// 4. Borda: Se a fila ficou vazia, o fim também tem que ser null
	if (comeco == nullptr) {
		cout << "Fila ficou vazia" << endl;
		fim = nullptr;
	}

	// 5. Limpa a memória (delete)
	delete temp;
}

// --- DICA DE PROVA: REMOVER DO MEIO (BUSCA) ---
void FilaDeProcessos::executarEspecif(int pid) {
	if (comeco == nullptr) {
		cout << "Fila Vazia!" << endl;
		return;
	}
	// Precisamos de dois ponteiros para "costurar" a lista quando removermos alguém
	Node* atual = comeco;
	Node* anterior = nullptr;

	while (atual != nullptr) {
		if (atual->processo->getPid() == pid) {
			// Achou! Executa primeiro.
			atual->processo->execute();

			// CASO 1: É o primeiro da fila?
			if (atual == comeco) {
				comeco = atual->proximo; // Só move o início
			}
			// CASO 2: É do meio ou fim?
			else {
				// O anterior "pula" o atual e liga direto no próximo
				anterior->proximo = atual->proximo;
			}

			// CASO 3: Removeu o último?
			if (atual == fim) {
				fim = anterior; // O fim volta um passo
			}

			delete atual; // Tchau
			cout << "Processo removido com sucesso." << endl;
			return;
		}
		else {
			// Não achou, avança os dois ponteiros
			anterior = atual;
			atual = atual->proximo;
		}
	}
	cout << "PID: " << pid << "Nao encontrado na fila." << endl;
}

void FilaDeProcessos::imprimir() const {
	if (comeco == nullptr) {
		cout << "Fila vazia." << endl;
		return;
	}
	Node* temp = comeco;
	cout << "--------- Fila de processos ---------" << endl;
	// Loop simples de percorrer a lista
	while (temp != nullptr) {
		cout << "PID: " << temp->processo->getPid() << endl;
		temp = temp->proximo; // Avança
	}
	cout << "-------------------------------------" << endl;
}

// --- DICA DE PROVA: SALVAR COM "ETIQUETA" ---
void FilaDeProcessos::salvarEmArquivo(string nomeArquivo) const {
	ofstream arquivo;
	arquivo.open(nomeArquivo);

	if (arquivo.is_open()) {
		Node* temp = comeco;

		while (temp != nullptr) {
			// 1. Grava o TIPO (1, 2, 3 ou 4) primeiro!
			// Isso é vital para o "Carregar" saber qual 'new' fazer.
			arquivo << temp->processo->getTipo() << " ";

			// 2. O processo grava seus próprios dados
			temp->processo->salvar(arquivo);

			temp = temp->proximo;
		}
		arquivo.close();
		cout << "Arquivo salvo com sucesso!" << endl;
	}
	else {
		cout << "Erro ao abrir o arquivo." << endl;
	}
}

// --- DICA DE PROVA: CARREGAR (FACTORY) ---
void FilaDeProcessos::carregarDeArquivo(string nomeArquivo) {
	ifstream arquivo(nomeArquivo);

	// Variáveis auxiliares para leitura
	int tipo, pid;
	float n1, n2;
	char op;

	if (arquivo.is_open()) {
		// LIMPEZA: Antes de carregar, esvazia a fila atual
		// Reutilizamos o método executarProx() que já remove e deleta.
		while (comeco != nullptr) {
			executarProx();
		}
	}
	else {
		return;
	}

	// LOOP: "Enquanto conseguir ler o TIPO..."
	while (arquivo >> tipo) {
		switch (tipo) {
		case 1: // Computing
			arquivo >> pid >> n1 >> op >> n2;
			adicionar(new ComputingProcess(pid, n1, op, n2));
			break;
		case 2: // Writing
			arquivo >> pid >> n1 >> op >> n2;
			adicionar(new WritingProcess(pid, n1, op, n2));
			break;
		case 3: // Reading
			arquivo >> pid;
			// DICA CRUCIAL: "*this"
			// Passamos a PRÓPRIA FILA como referência para o processo.
			adicionar(new ReadingProcess(pid, *this));
			break;
		case 4: // Printing
			arquivo >> pid;
			adicionar(new PrintingProcess(pid, *this));
			break;
		}
	}
	arquivo.close();
	cout << "Fila carregada!" << endl;
}