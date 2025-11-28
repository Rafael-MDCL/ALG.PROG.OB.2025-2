#include "FilaDeProcessos.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include <iostream>

using namespace std;

FilaDeProcessos::FilaDeProcessos() : comeco(nullptr), fim(nullptr) {};

FilaDeProcessos::~FilaDeProcessos() {};

void FilaDeProcessos::adicionar(Processo* p) {
	Node* novoNode = new Node(p);

	if (comeco == nullptr) {
		comeco = novoNode;
		fim = novoNode;
	}
	else {
		fim->proximo = novoNode;
		fim = novoNode;
	}
};

void FilaDeProcessos::executarProx() {
	if (comeco == nullptr) {
		cout << "Fila Vazia!" << endl;
		return;
	}
	Node* temp = comeco;
	
	temp->processo->execute();

	comeco = comeco->proximo;

	if (comeco == nullptr) {
		cout << "Fila ficou vazia" << endl;
		fim = nullptr;
	}
	delete temp;
}

void FilaDeProcessos::executarEspecif(int pid) {
	if (comeco == nullptr) {
		cout << "Fila Vazia!" << endl;
		return;
	}
	Node* atual = comeco;
	Node* anterior = nullptr;

	while (atual != nullptr) {
		if (atual->processo->getPid() == pid) {
			atual->processo->execute();
			if (atual == comeco) {
				comeco = atual->proximo;
			}
			else {
				anterior->proximo = atual->proximo;

			}
			if (atual == fim) {
				fim = anterior;
			}
			delete atual;

			cout << "Processo removido com sucesso." << endl;
			return;
		}
		else {
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

	while (temp != nullptr){
		cout << "PID: " << temp->processo->getPid() << endl;

		temp = temp->proximo;
	}
	cout << "-------------------------------------" << endl;
}

void FilaDeProcessos::salvarEmArquivo(string nomeArquivo) const {
	ofstream arquivo;
	arquivo.open(nomeArquivo);

	if (arquivo.is_open()) {
		Node* temp = comeco;

		while (temp != nullptr) {
			arquivo << temp->processo->getTipo() << " ";

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

void FilaDeProcessos::carregarDeArquivo(string nomeArquivo) {
	ifstream arquivo(nomeArquivo);
	int variavelTipo;

	int tipo, pid;
	float n1, n2;
	char op;

	if (arquivo.is_open()) {
		while (comeco != nullptr) {
			executarProx();
		}
	}
	else{
		return;
	}
	while (arquivo >> tipo) {
		switch (tipo) {
		case 1:
			arquivo >> pid >> n1 >> op >> n2;

			adicionar(new ComputingProcess(pid, n1, op, n2));
			break;
		case 2:
			arquivo >> pid >> n1 >> op >> n2;

			adicionar(new WritingProcess(pid, n1, op, n2));
			break;
		case 3:
			arquivo >> pid;

			adicionar(new ReadingProcess(pid, *this));
			break;
		case 4:
			arquivo >> pid;

			adicionar(new PrintingProcess(pid, *this));
			break;
		}
	}
	arquivo.close();
	cout << "Fila carregada!" << endl;
}