#pragma once
#include <string>
#include "Calculadora.h"
using namespace std;

class Funcionario {
private:
	string nome;
	string endereco;
	calculadora calc;
public:
	Funcionario(string nome, string endereco, string corCalc);

	string getNome() const;
	void setNome(string nome);

	string getEndereco() const;
	void setEndereco(string endereco);

	const calculadora& getCalc() const;
	void setCalc(const calculadora& novaCalc);

	double soma(double num1, double num2);
	double subtrai(double num1, double num2);
	double multiplica(double num1, double num2);
	double divide(double num1, double num2);

	int eleva_ao_quadrado(int x);
	int eleva_ao_cubo(int x);

	void imprime_info();
};