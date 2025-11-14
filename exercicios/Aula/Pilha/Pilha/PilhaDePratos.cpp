#include <iostream>
#include "PilhaDePratos.h"
using namespace std;

PilhaDePratos::PilhaDePratos() {
	quantidade = 0;
}

void PilhaDePratos::push(int qtd) {
	quantidade += qtd;
}
void PilhaDePratos::pop(int qtd) {
	if (quantidade > qtd) {
		quantidade -= qtd;
	}
	else {
		quantidade = 0;
	}
}

int PilhaDePratos::getQuantidade() const {
	return quantidade;
}