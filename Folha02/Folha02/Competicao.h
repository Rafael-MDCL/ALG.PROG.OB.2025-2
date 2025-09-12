#pragma once
#include "Data.h"
#include <string>

using namespace std;

class Competicao {
protected:
	string nome;
	Data data;
public:
	Competicao(string nome, Data data);

	void setData(Data data);
	void setNome(string nome);

	string getNome() const;
	Data getData() const;

	void imprime_data();
};