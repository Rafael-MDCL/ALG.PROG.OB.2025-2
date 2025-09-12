#pragma once
#include <string>

using namespace std;

class Atleta
{
protected:
	string nome;
	int idade;

public:
	Atleta(string nome, int idade);

	void setNome(string n);
	void setIdade(int id);

	string getNome() const;
	int getIdade() const;

	virtual void imprime_info();

};

