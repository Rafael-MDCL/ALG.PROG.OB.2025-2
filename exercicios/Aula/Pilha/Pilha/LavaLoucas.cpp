#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "Simulador.h"
using namespace std;

int main() {
	srand(time(NULL));
	Simulador sim;
	int turnos = 0;
	cout << "Bem vindo ao lava loucas, digite a quantidade de turnos: " << endl;
	cin >> turnos;

	sim.executar(turnos);

	cout << "A quantidade total foi de: " << sim.getQuantidadeTotal() << endl;
	return 0;
}