#pragma once

#include <string>
#include <iostream>
#include "Competicao.h"
#include "Atleta.h"
using namespace std;

class Corredor : public Atleta {
protected:
	int peso;
	Competicao competicao;
public:
	Corredor(string nome, int idade, int peso, Competicao competicao);
	void setPeso(int peso);
	int getPeso() const;

	void setCompeticao(Competicao competicao);
	Competicao getCompeticao() const;

	void imprime_competicao();
	virtual void imprime_info();
};

// Falta a 6, dica:#pragma once
//#include "Atleta.h"
//
//class InformacoesAtleta {
//public:
//    void imprime_exclusivos_atleta(Atleta* atleta);
//    void imprime_informacoes_atleta(Atleta* atleta);
//}; #include "InformacoesAtleta.h"
//#include "Nadador.h"
//#include "Corredor.h"
//#include <iostream>
//using namespace std;
//
//void InformacoesAtleta::imprime_exclusivos_atleta(Atleta* atleta) {
//    if (Nadador* n = dynamic_cast<Nadador*>(atleta)) {
//        cout << "É um nadador, e sua categoria é: " << n->get_categoria() << endl;
//    }
//    else if (Corredor* c = dynamic_cast<Corredor*>(atleta)) {
//        cout << "É um corredor, e o peso deste corredor é: " << c->getPeso() << endl;
//    }
//}
//
//void InformacoesAtleta::imprime_informacoes_atleta(Atleta* atleta) {
//    atleta->imprime_info(); // Chama o método polimórfico
//    imprime_exclusivos_atleta(atleta); // Chama as informações exclusivas
//}