#pragma once
#include "Processo.h"
#include <iostream>
#include <fstream>

class WritingProcess : public Processo {
private:
	float n1;
	float n2;
	char operacao;
public:
	WritingProcess(int pid, float n1, char operacao, float n2);
	~WritingProcess();

	void execute() override;
	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};

// Idêntico ao ComputingProcess. Comentários lá.