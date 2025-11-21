#pragma once
#include "FilaDeProcessos.h" // OBRIGATÓRIO: O Sistema precisa conhecer a Fila.

class Sistema {
private:
	// --- CONCEITO CHAVE: COMPOSIÇÃO ---
	// O Sistema TEM UMA Fila.
	// Note que aqui NÃO é um ponteiro (*). É a instância direta.
	// Vantagem: Quando o 'Sistema' for destruído, a 'fila' morre junto automaticamente.
	// Não precisamos dar 'delete fila' no destrutor do Sistema.
	FilaDeProcessos fila;

	// Contador para garantir PIDs únicos (1, 2, 3...).
	// É privado para ninguém de fora bagunçar a contagem.
	int pidContador;

	// Método auxiliar (Helper).
	// É 'private' porque só o método Menu() vai chamar ele.
	// O main() não precisa saber que esse método existe.
	void criarProcessos();

public:
	// Construtor: Vai inicializar o pidContador = 1.
	Sistema();

	// O único método que o main() chama.
	// Contém o loop principal (while != sair).
	void Menu();
};