#include "Calculadora.h"
#include "Empresa.h"
#include "FuncionarioCaixa.h"
#include <iostream>
using namespace std;
int main() {

    Funcionario caixa1("Rafa", "Rua das Cucuias", "Roxa");
    Funcionario caixa2("Kauan", "Rua do cantinho", "Verde");

    cout << "2 + 2 = " << caixa1.getCalc().soma(2, 2) << endl;
    cout << "5 - 4 = " << caixa1.getCalc().subtracao(5, 4) << endl;
    cout << "2 * 3 = " << caixa1.getCalc().multiplicacao(2, 3) << endl;

    cout << endl; 

    cout << "6 / 3 = " << caixa2.getCalc().divisao(6, 3) << endl;
    cout << "7 + 2 = " << caixa2.getCalc().soma(7, 2) << endl;
    cout << "8 * 3 = " << caixa2.getCalc().multiplicacao(8, 3) << endl;

    cout << endl;

    Empresa Furrys("FurryCorp",
        "Rafa", "Rua das Cucuias", "Roxa",
        "Kauan", "Rua do cantinho", "Verde");

    Furrys.imprime_info();

    return 0;
}