#include <iostream>
#include "pessoa.h"
using namespace std;

int main(){

    Pessoa p1 ("Rafa", 20, 2.00, 1, "Rua Boa Vista, 675");
    Pessoa p2 ("Kauan", 19, 1.60, 1, "Dom Joao Bosco, 380");
    Pessoa p3 ("Patrick", 20, 1.90, 0, "Rua estranha do Patrick, 666");

    cout << "===== Informacoes das pessoas =====" << endl;

    p1.imprime_info();
    cout << (p1.is_filho_unico() ?  "Filho(a) unico(a)" : "Não é filho único") << endl << endl;
    p2.imprime_info();
    cout << (p2.is_filho_unico()? "Filho(a) unico(a)" : "Não é filho único") << endl << endl;
    p3.imprime_info();
    cout << (p3.is_filho_unico()? "Filho(a) unico(a)" : "Não é filho único") << endl << endl;

    return 0;
}