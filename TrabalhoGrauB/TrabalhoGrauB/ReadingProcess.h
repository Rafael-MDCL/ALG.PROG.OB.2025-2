#pragma once
#include "Processo.h"
#include <fstream>

class FilaDeProcessos;

class ReadingProcess : public Processo {
private:
	FilaDeProcessos& fila;

public:
	ReadingProcess(int pid, FilaDeProcessos& filaDoSistema);
	~ReadingProcess();

	void execute() override;


	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};