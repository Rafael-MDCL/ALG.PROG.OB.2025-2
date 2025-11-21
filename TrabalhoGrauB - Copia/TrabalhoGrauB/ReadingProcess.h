#pragma once
#include "Processo.h"
#include <fstream>

// --- CONCEITO CHAVE: FORWARD DECLARATION (Declaração Antecipada) ---
// DICA DE PROVA: Por que não fizemos #include "FilaDeProcessos.h" aqui?
// Problema: A Fila inclui os Processos. Se o Processo incluir a Fila, cria um ciclo.
// (O ovo precisa da galinha e a galinha precisa do ovo -> Erro de Compilação).
// Solução: A linha abaixo avisa ao compilador: "Existe uma classe com esse nome, não surta.
// Eu vou te dar os detalhes dela lá no arquivo .cpp".
class FilaDeProcessos;

class ReadingProcess : public Processo {
private:
	// --- CONCEITO CHAVE: REFERÊNCIA (&) ---
	// DICA DE PROVA: Por que tem esse '&'?
	// 1. Lógica: O processo de leitura precisa adicionar itens na Fila DO SISTEMA.
	//    Ele precisa mexer na original, não numa cópia.
	// 2. Regra: Se você tirar o '&', o C++ cria uma cópia da fila só para esse processo.
	//    Você vai adicionar itens na cópia, ela vai ser destruída, e a fila real fica vazia.
	FilaDeProcessos& fila;

public:
	// O construtor recebe a referência da fila para guardar
	ReadingProcess(int pid, FilaDeProcessos& filaDoSistema);

	~ReadingProcess();

	void execute() override;

	int getTipo() const override;
	void salvar(std::ofstream& arquivo) const override;
};