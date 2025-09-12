#pragma once

#include <string>
#include <iostream>
#include "Atleta.h"
using namespace std;

class Nadador : public Atleta {
protected:
	string categoria;
public:
	Nadador(string nome, int idade, string categoria) : Atleta(nome, idade), categoria(categoria) { }

	void setCategoria(string categoria);
	string getCategoria() const;

	void imprime_info() {
		Atleta::imprime_info();
		cout << "Categoria: "<< getCategoria() <<endl;
	}
};