#include "Calculadora.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

calculadora::calculadora(string cor)
    : memoria(0), cor(cor) {
}


//getters
double calculadora::getMemoria() const {
    return memoria;
}
string calculadora::getCor() const {
    return cor;
}
//setters
void calculadora :: setMemoria(double val) {
    memoria = val;
}
void calculadora::setCor(string cor) {
    this->cor = cor;
}

// funções

double calculadora::soma(double num1, double num2) const {
    return num1 + num2;
}

double calculadora::subtracao(double num1, double num2) const {
    return num1 - num2;
}

double calculadora::multiplicacao(double num1, double num2) const {
    return num1 * num2;
}

double calculadora::divisao(double num1, double num2) const {
    if (num2 == 0) {
        throw invalid_argument("Nenhum numero pode ser dividido por 0");
    }
    else {
        return num1 / num2;
    }
}

int calculadora::eleva_ao_quadrado(int x) const {
    return pow(x, 2);
}

int calculadora::eleva_ao_cubo(int x) const {
    return pow(x, 3);
}

void calculadora::imprime_info() {
    cout << "--- INFO DA CALCULADORA---" << endl;
    cout << "Cor: " << cor << endl;
    cout << "Memoria: " << memoria << endl;
    cout << "--------------------------" << endl;
}