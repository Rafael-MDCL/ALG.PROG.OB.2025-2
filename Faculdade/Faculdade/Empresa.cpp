#include "Empresa.h"
#include "FuncionarioCaixa.h"
#include "calculadora.h"
#include <iostream>
using namespace std;

Empresa::Empresa(string nome,
    string nomeC1, string locaC1, string corC1,
    string nomeC2, string locaC2, string corC2)
    : nome(nome),
        caixa1(nomeC1, locaC1, corC1),
        caixa2(nomeC2, locaC2, corC2){ }

string Empresa::getNome() const {
    return nome;
}

const Funcionario& Empresa::getCaixa1() const{
    return caixa1;
}

const Funcionario& Empresa::getCaixa2() const {
    return caixa2;
}

void Empresa::setNome(const string& n) {
    nome = n;
}
void Empresa::setFuncionarios(const Funcionario& f1, const Funcionario& f2) {
    caixa1 = f1;
    caixa2 = f2;
}

void Empresa::imprime_info() {
    cout << "-------------------" << endl;
    cout << "Nome da empresa: " << getNome() << endl;
    cout << "Funcionario 1: " << endl;
    caixa1.imprime_info();
    cout << "Funcionario 2:" << endl;
    caixa2.imprime_info();
    cout << "-------------------" << endl;

}
