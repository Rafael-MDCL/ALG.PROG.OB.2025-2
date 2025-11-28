#pragma once
#include "Processo.h"
#include <iostream>
#include <fstream>

class FilaDeProcessos; 

class PrintingProcess : public Processo {
private:
	FilaDeProcessos& fila;

public:
	PrintingProcess(int pid, FilaDeProcessos& filaDoSistema);
	~PrintingProcess();

	void execute() override;
	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};