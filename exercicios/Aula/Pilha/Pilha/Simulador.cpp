#include "Simulador.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Simulador::Simulador() {
}


void Simulador::executar(int turnos) {
	for (int i = 0; i < turnos; i++) {
		Lavador();
		Secador();
	}
}

void Simulador::Lavador() {
	int pratosLavados = (rand() % 5) + 1;
	
	Pilha.push(pratosLavados);
}

void Simulador::Secador() {
	int pratosSecos = (rand() % 3) + 1;

	Pilha.pop(pratosSecos);
}

int Simulador::getQuantidadeTotal() const {
	return Pilha.getQuantidade();
}