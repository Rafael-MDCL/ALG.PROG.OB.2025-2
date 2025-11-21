#include "Sistema.h" // OBRIGATÓRIO: Precisa conhecer a classe principal que gerencia tudo.
#include <iostream>

using namespace std;

// A função main é o PONTO DE ENTRADA. O C++ sempre começa a executar por aqui.
int main() {
	cout << "Iniciando o Sistema..." << endl;

	// --- DICA DE PROVA: INSTÂNCIA NA STACK (PILHA) ---
	// "Sistema sistema;"
	// 1. Isso chama o CONSTRUTOR Sistema() automaticamente (iniciando o pidContador = 1).
	// 2. O objeto é criado na memória STACK (Pilha).
	//    Vantagem: Quando a função main terminar, o DESTRUTOR ~Sistema()
	//    será chamado automaticamente, limpando tudo.
	//    Se usássemos "new Sistema()", teríamos que usar "delete" no final manualmente.
	Sistema sistema;

	// --- BLOQUEIO DE EXECUÇÃO ---
	// Chamamos o método Menu().
	// O programa vai "entrar" nessa linha e ficar preso lá dentro (no loop while)
	// até o usuário escolher a opção 6 (Sair).
	sistema.Menu();

	cout << "Programa encerrado." << endl;

	return 0; // Retorna 0 para o Sistema Operacional, indicando que não houve erros.
}