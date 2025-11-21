#include "WritingProcess.h"
#include <fstream>
#include <iostream>

using namespace std;

// Construtor: Idêntico ao do Computing.
// DICA DE PROVA: Nunca esqueça de chamar o construtor do pai ": Processo(pid)"
// na lista de inicialização. Sem isso, o PID fica com lixo de memória.
WritingProcess::WritingProcess(int pid, float n1, char operacao, float n2)
	: Processo(pid), n1(n1), operacao(operacao), n2(n2) {
}

WritingProcess::~WritingProcess() {
}

// Retorna a "etiqueta" 2.
// Isso será usado no switch do "carregarDeArquivo" para saber que é um WritingProcess.
int WritingProcess::getTipo() const {
	return 2;
}

// Método salvar (para persistência da fila)
// Grava os dados no arquivo de backup do sistema.
void WritingProcess::salvar(ofstream& arquivo) const {
	arquivo << pid << " " << n1 << " " << operacao << " " << n2 << endl;
}

// Método execute (Ação real do processo)
void WritingProcess::execute