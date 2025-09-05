#include "Atleta.h"
#include <iostream>
#include <string>

using namespace std;

Atleta :: Atleta(string nome, int idade) :
	nome(nome), idade(idade){ }

string Atleta::getNome() const {
	return nome;
}
int Atleta::getIdade() const {
	return idade;
}

void Atleta::setNome(string n) {
	nome = n;
}

void Atleta::setIdade(int id) {
	idade = id;
}

void Atleta::imprime_info() {
	cout << "----- Atletas -----" << endl;
	cout << "Nome: " << getNome() << endl;
	cout << "Idade: " << getIdade() << endl;
	cout << "-------------------" << endl;
}