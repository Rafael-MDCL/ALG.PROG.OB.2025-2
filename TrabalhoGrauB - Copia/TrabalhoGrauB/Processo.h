#pragma once
// DICA DE PROVA: Sempre inclua <fstream> quando a classe for lidar com arquivos.
// Sem isso, o tipo 'std::ofstream' não é reconhecido e dá erro em cascata.
#include <fstream> 

class Processo {
	// PROTECTED:
	// Diferente de 'private' (que só essa classe vê) e 'public' (que todos veem).
	// Protected permite que as classes FILHAS (ComputingProcess, etc.) acessem 'pid' diretamente.
protected:
	int pid;

public:
	Processo(int pid);

	// --- CRUCIAL PARA A PROVA ---
	// Destrutor Virtual (virtual ~Processo).
	// REGRA: Se uma classe tem métodos virtuais, o destrutor TAMBÉM tem que ser virtual.
	// POR QUÊ: Quando você fizer "delete ponteiroProcesso", o virtual garante que
	// o C++ chame o destrutor do Filho primeiro, limpando a memória corretamente.
	virtual ~Processo();

	int getPid() const;

	// --- MÉTODOS VIRTUAIS PUROS (= 0) ---
	// O "= 0" significa: "Eu não sei como fazer isso, meu filho que se vire".
	// 1. Torna esta classe ABSTRATA (Proibido fazer 'new Processo()').
	// 2. OBRIGA todas as subclasses a implementarem esses métodos.
	// 3. Permite o POLIMORFISMO: Chamar lista[i]->execute() e cada um agir de um jeito.

	virtual int getTipo() const = 0; // Vai retornar 1, 2, 3 ou 4

	virtual void execute() = 0;

	// DICA DE SINTAXE:
	// Note o "std::ofstream&". O "&" (referência) é OBRIGATÓRIO aqui.
	// Você nunca pode passar um arquivo por cópia (sem &) em C++.
	virtual void salvar(std::ofstream& arquivo) const = 0;
};