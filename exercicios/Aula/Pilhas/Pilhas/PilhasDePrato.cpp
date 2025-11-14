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
	quantidade -= qtd;
}

int 