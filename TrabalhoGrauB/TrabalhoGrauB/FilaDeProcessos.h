#pragma once
#include "Node.h"
#include "Processo.h"
#include <string>
#include <fstream>

class FilaDeProcessos {
private:
	Node* comeco;
	Node* fim;
public:
	FilaDeProcessos();
	~FilaDeProcessos();

	void adicionar(Processo* p);
	void executarProx();
	void executarEspecif(int pid);
	void imprimir() const;
	void salvarEmArquivo(std::string nomeArquivo) const;
	void carregarDeArquivo(std::string nomeArquivo);
};