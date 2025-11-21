#include "PrintingProcess.h"
#include "FilaDeProcessos.h"

using namespace std;

// Retorna a "etiqueta" 4.
int PrintingProcess::getTipo() const {
	return 4;
}

// No salvar, igual ao ReadingProcess, só guardamos o PID.
// Não faz sentido salvar o conteúdo da fila inteira aqui, 
// pois a fila é do Sistema, não deste processo específico.
void PrintingProcess::salvar(std::ofstream& arquivo) const {
	arquivo << pid << std::endl;
}

// --- DICA DE PROVA: CONSTRUTOR COM REFERÊNCIA ---
// Novamente: Se a classe tem um atributo que é REFERÊNCIA (&),
// você OBRIGATORIAMENTE precisa inicializá-lo na lista após os dois pontos (:).
// ": fila(filaDoSistema)"
PrintingProcess::PrintingProcess(int pid, FilaDeProcessos& filaDoSistema)
	: Processo(pid), fila(filaDoSistema) {
}

PrintingProcess::~PrintingProcess() {};

// O método execute é simples: ele delega o trabalho para a fila.
// Como temos a referência da fila original ("fila."), chamamos o método imprimir dela.
void PrintingProcess::execute() {
	fila.imprimir();
}