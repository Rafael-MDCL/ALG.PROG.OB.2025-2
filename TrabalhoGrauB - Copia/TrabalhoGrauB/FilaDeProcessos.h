#pragma once
#include "Node.h"     // Precisa conhecer o "Vagão"
#include "Processo.h" // Precisa conhecer a "Carga"
#include <string>
#include <fstream>

class FilaDeProcessos {
	// PRIVATE:
	// Só a própria fila pode mexer nos ponteiros internos.
	// O mundo exterior só pede "adicionar", não mexe nos nós diretamente.
private:
	// --- DICA DE PROVA: POR QUE DOIS PONTEIROS? ---
	// 1. 'comeco' (Head): Essencial para qualquer lista. É onde começamos a ler/remover.
	// 2. 'fim' (Tail): É uma OTIMIZAÇÃO.
	//    Sem o 'fim', para adicionar alguém, teríamos que percorrer a lista toda (O(n)).
	//    Com o 'fim', sabemos exatamente onde conectar o novo nó instantaneamente (O(1)).
	Node* comeco;
	Node* fim;

public:
	// Construtor: Vai garantir que comeco e fim iniciem como nullptr (Lista Vazia).
	FilaDeProcessos();

	// Destrutor: Vai percorrer a lista deletando nó por nó para limpar a memória RAM.
	~FilaDeProcessos();

	// Recebe um ponteiro de Processo (Polimorfismo: aceita qualquer filho).
	void adicionar(Processo* p);

	// Remove do início (FIFO - First In, First Out).
	void executarProx();

	// O método mais complexo: Busca pelo ID, executa e remove (pode ser do meio).
	void executarEspecif(int pid);

	// --- DICA DE SINTAXE: O QUE É 'const'? ---
	// Colocar 'const' depois do nome da função promete ao compilador que:
	// "Este método APENAS LÊ dados. Ele NÃO ALTERA o comeco, o fim ou os nós."
	// É ótimo para segurança e para métodos de impressão/salvamento.
	void imprimir() const;

	void salvarEmArquivo(std::string nomeArquivo) const;

	// Este não é const, pois ele vai alterar a fila (adicionar novos processos).
	void carregarDeArquivo(std::string nomeArquivo);
};