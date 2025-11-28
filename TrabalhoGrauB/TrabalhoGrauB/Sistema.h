#pragma once
#include "FilaDeProcessos.h"

class Sistema {
private:
	FilaDeProcessos fila;

	int pidContador;
	
	void criarProcessos();
public:
	Sistema();

	void Menu();
};