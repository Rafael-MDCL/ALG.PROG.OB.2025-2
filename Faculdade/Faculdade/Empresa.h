#pragma once
#include <string>
#include "FuncionarioCaixa.h"
using namespace std;

class Empresa {
private:
	string nome;
	Funcionario caixa1;
	Funcionario caixa2;
public:
	Empresa(string nome,
		string nomeC1, string locaC1, string corC1,
		string nomeC2, string locaC2, string corC2);

	//getters
	string getNome() const;
	const Funcionario& getCaixa1() const;
	const Funcionario& getCaixa2() const;

	//setters

	void setNome(const string& n);
	void setFuncionarios(const Funcionario& f1, const Funcionario& f2);

	void imprime_info();
};