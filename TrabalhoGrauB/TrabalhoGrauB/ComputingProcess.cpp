#include "ComputingProcess.h"
#include <iostream>
#include <fstream>

using namespace std;

ComputingProcess::ComputingProcess(int pid, float n1, char operacao, float n2) : Processo(pid), n1(n1), operacao(operacao), n2(n2) {

}

ComputingProcess::~ComputingProcess() {
}

int ComputingProcess::getTipo() const {
	return 1; // Código 1 para Cálculo
}

void ComputingProcess::salvar(std::ofstream& arquivo) const {
	arquivo << pid << " " << n1 << " " << operacao << " " << n2 << std::endl;
}

void ComputingProcess::execute() {
	float resultado = 0;
	bool concluido = true;

	cout << "Processo: " << pid << " \nCalculando: " << n1 << " " << operacao << " " << n2 << endl;
	
		switch (operacao) {
		case '+':
			resultado = n1 + n2;
			break;

		case '-':
			resultado = n1 - n2;
			break;

		case '*':
			resultado = n1 * n2;
			break;

		case '/':
			if (n2 == 0) {
				cout << "ERRO!: Nenhum numero pode ser dividido por 0." << endl;
				concluido = false;
				break;
			}
			else {
				resultado = n1 / n2;
				break;
			}

		default:
			cout << "Operacao invalida." << endl;
			concluido = false;
			break;
	}
		if (concluido) {
			cout << "Resultado: " << resultado << endl;
		}
}