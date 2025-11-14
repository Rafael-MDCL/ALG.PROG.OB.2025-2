#pragma once
#include "PilhaDePratos.h"

class Simulador {
private:
	PilhaDePratos Pilha;
	void Lavador();
	void Secador();
public:
	Simulador();


	void executar(int Turnos);
	int getQuantidadeTotal() const;
};