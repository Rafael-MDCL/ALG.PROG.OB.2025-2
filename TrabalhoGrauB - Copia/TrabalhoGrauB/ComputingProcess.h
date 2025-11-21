#pragma once
#include "Processo.h" // OBRIGATÓRIO: Precisa conhecer a classe mãe
#include <iostream>
#include <fstream> // OBRIGATÓRIO: Por causa do std::ofstream no método salvar

// DICA DE PROVA (Sintaxe de Herança):
// "class Filha : public Mae"
// O ": public" significa que tudo que é publico na mãe continua publico na filha.
// Sem isso, a herança fica 'private' e ninguém consegue usar os métodos da mãe.
class ComputingProcess : public Processo {

	// PRIVATE:
	// Esses atributos (n1, n2, operacao) existem APENAS neste tipo de processo.
	// A classe mãe (Processo) nem sabe que eles existem.
	// Eles são 'private' porque só esta classe deve mexer neles.
private:
	float n1;
	float n2;
	char operacao;

public:
	// O construtor recebe o PID (para passar pro pai) e os dados específicos (pra ele)
	ComputingProcess(int pid, float n1, char operacao, float n2);

	~ComputingProcess();

	// --- DICA DE OURO: 'override' ---
	// A palavra 'override' é opcional, mas USE SEMPRE NA PROVA.
	// Ela serve como um "corretor ortográfico".
	// Se você errar o nome ou os parâmetros do método da mãe, o compilador avisa.
	// Aqui estamos cumprindo a promessa feita no Processo.h (o "= 0").
	void execute() override;
	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};