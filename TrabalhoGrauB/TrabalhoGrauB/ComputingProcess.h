#pragma once
#include "Processo.h"
#include <iostream>
#include <fstream>

class ComputingProcess : public Processo {
private:
	float n1;
	float n2;
	char operacao;
public:
	ComputingProcess(int pid, float n1, char operacao, float n2);
	~ComputingProcess();

	void execute() override;
	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};