#pragma once
#include <fstream>

class Processo {
protected:
	int pid;
public:
	Processo(int pid);
	virtual ~Processo();

	int getPid() const;

	virtual int getTipo() const = 0;
	virtual void execute() = 0;
	virtual void salvar(std::ofstream& arquivo) const = 0;
};