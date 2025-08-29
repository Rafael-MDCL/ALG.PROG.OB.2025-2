#include <iostream>
#include "FuncionarioCaixa.h"
#include "Calculadora.h"
using namespace std;

Funcionario::Funcionario(string nome, string endereco, string corCalc)
	: nome(nome), endereco(endereco), calc(corCalc) {}


// Getters
string Funcionario::getNome() const {
	return nome;
}
string Funcionario::getEndereco() const {
	return endereco;
}
const calculadora& Funcionario::getCalc() const {
	return calc; 
}

// Setters
void Funcionario::setNome(string n) {
	nome = n;
}
void Funcionario::setEndereco(string loca) {
	endereco = loca;
}
void Funcionario::setCalc(const calculadora& novaCalc) {
	calc = novaCalc;
}

void Funcionario::imprime_info() {
	cout << "--- Funcionario ---" << endl;
	cout << "Nome: " << getNome() << endl;
	cout << "Endereco: " << getEndereco() << endl;
	cout << "-------------------" << endl;
	cout << "--- Calculadora ---" << endl;
	cout << " Cor: " << getCalc().getCor() << endl;
	cout << " Memoria: " << getCalc().getMemoria() << endl;
	cout << "-------------------" << endl;
}