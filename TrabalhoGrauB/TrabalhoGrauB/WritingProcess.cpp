#include "WritingProcess.h"
#include <fstream>
#include <iostream>

using namespace std;

WritingProcess::WritingProcess(int pid, float n1, char operacao, float n2) : Processo(pid), n1(n1), operacao(operacao), n2(n2) {

}

WritingProcess::~WritingProcess() {
}

int WritingProcess::getTipo() const {
	return 2; // Código 2 para Gravação
}

void WritingProcess::salvar(ofstream& arquivo) const {
	arquivo << pid << " " << n1 << " " << operacao << " " << n2 << endl;
}

void WritingProcess::execute() {
	ofstream arquivo;
	arquivo.open("computation.txt", ios::app);
	if (arquivo.is_open()) {
		arquivo << n1 << " " << operacao << " " << n2 << endl;
		arquivo.close();
	}

}
