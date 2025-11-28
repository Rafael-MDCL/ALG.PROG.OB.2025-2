#include "PrintingProcess.h"
#include "FilaDeProcessos.h".

using namespace std;

int PrintingProcess::getTipo() const {
	return 4; // Código para Exibição
}

void PrintingProcess::salvar(std::ofstream& arquivo) const {
	arquivo << pid << std::endl;
}

PrintingProcess::PrintingProcess(int pid, FilaDeProcessos& filaDoSistema) : fila(filaDoSistema), Processo(pid) {}
PrintingProcess::~PrintingProcess() {};

void PrintingProcess::execute() {
	fila.imprimir();
}