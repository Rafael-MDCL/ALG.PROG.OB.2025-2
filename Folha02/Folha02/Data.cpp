#include "Data.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Data::Data(int dia, int mes, int ano) :
	dia(dia), mes(mes), ano(ano){ }

int Data::getDia() const {
	return dia;
}

int Data::getMes() const {
	return mes;
}

int Data::getAno() const {
	return ano;
}

void Data::setDia(int DD) {
	dia = DD;
}

void Data::setMes(int MM) {
	mes = MM;
}

void Data::setAno(int AAAA) {
	ano = AAAA;
}

void Data::imprime_data() {
	cout << "-------------------" << endl;
	cout << setfill('0') << setw(2) << getDia() << "/" << setfill('0') << setw(2) << getMes() << "/" << getAno() << endl;
	cout << "-------------------";
}