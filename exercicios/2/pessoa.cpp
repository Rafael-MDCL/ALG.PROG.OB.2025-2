#include "pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa(std:: string name, int age, double height, int brothers, std::string adress){
    nome = name;
    idade = age;
    altura = height;
    quantidadeDeIrmaos = brothers;
    endereco = adress;
}

void Pessoa::imprime_info() const {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Altura: " << altura << " m" << endl;
    cout << "Quantidade de irmaos: " << quantidadeDeIrmaos << endl;
    cout << "Endereco: " << endereco << endl;
}
bool Pessoa::is_filho_unico() const {
    return quantidadeDeIrmaos == 0;
}