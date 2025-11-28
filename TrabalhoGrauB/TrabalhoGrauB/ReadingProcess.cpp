#include "ReadingProcess.h"
#include "FilaDeProcessos.h"
#include "ComputingProcess.h"

using namespace std;

ReadingProcess::ReadingProcess(int pid, FilaDeProcessos& filaDoSistema) : fila(filaDoSistema), Processo(pid) {}
ReadingProcess::~ReadingProcess() {};

int ReadingProcess::getTipo() const {
	return 3; // Código para leitura;
}

void ReadingProcess::salvar(std::ofstream& arquivo) const {
	arquivo << pid << std::endl; 
}

void ReadingProcess::execute() {
	float n1, n2;
	char op;

	ifstream arquivoLeitura("computation.txt");

	while (arquivoLeitura >> n1 >> op >> n2) {
		fila.adicionar(new ComputingProcess(0, n1, op, n2));
	}
	arquivoLeitura.close();

	ofstream arquivoLimpeza("computation.txt");
	arquivoLimpeza.close();
}