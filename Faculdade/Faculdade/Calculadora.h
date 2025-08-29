#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class calculadora {
private:
	double memoria;
	string cor;

public:
	calculadora(string cor);

	//Definindo alterações de valores (setters) e leitura de valores (getters)

	double getMemoria() const;
	void setMemoria(double val);

	string getCor() const;
	void setCor(string cor);

	//operações

	double soma(double num1, double num2) const;
	double subtracao(double num1, double num2) const;
	double multiplicacao(double num1, double num2) const;
	double divisao(double num1, double num2) const;
	int eleva_ao_quadrado(int x) const;
	int eleva_ao_cubo(int x) const;


	int eleva_ao_quadrado(int x);
	int eleva_ao_cubo(int x);

	void imprime_info();;

};

