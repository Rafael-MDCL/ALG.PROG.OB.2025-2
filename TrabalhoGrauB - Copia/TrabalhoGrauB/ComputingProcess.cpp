#include "ComputingProcess.h"
#include <iostream>
#include <fstream>

using namespace std;

// --- DICA DE PROVA: CONSTRUTOR DE FILHO ---
// Sintaxe: ClasseFilha(...) : ClasseMae(args), atributo(valor)...
// 1. ": Processo(pid)": OBRIGATÓRIO. Antes de criar o filho, precisamos construir o pai.
//    Passamos o 'pid' para ele guardar lá na classe Processo.
// 2. "n1(n1), ...": Inicialização dos atributos exclusivos desta classe.
ComputingProcess::ComputingProcess(int pid, float n1, char operacao, float n2)
	: Processo(pid), n1(n1), operacao(operacao), n2(n2) {
}

ComputingProcess::~ComputingProcess() {
}

// Implementação do método que era virtual puro (= 0) no pai.
int ComputingProcess::getTipo() const {
	return 1; // Retorna a "etiqueta" 1 para sabermos que é Cálculo na hora de carregar.
}

// --- DICA DE PROVA: SALVAR EM ARQUIVO ---
// O parâmetro é "std::ofstream& arquivo".
// O operador "<<" funciona igual ao cout, mas joga o texto dentro do arquivo.
// IMPORTANTE: Colocamos espaços " " entre as variáveis.
// Por que? Porque o comando de leitura (>>) usa espaços para separar os dados.
// Se gravássemos "10+5", o >> leria tudo como uma coisa só e daria erro.
void ComputingProcess::salvar(std::ofstream& arquivo) const {
	arquivo << pid << " " << n1 << " " << operacao << " " << n2 << std::endl;
}

void ComputingProcess::execute() {
	float resultado = 0;
	bool concluido = true; // Flag para saber se podemos imprimir o resultado final

	cout << "Processo: " << pid << " \nCalculando: " << n1 << " " << operacao << " " << n2 << endl;

	// --- DICA DE SINTAXE: SWITCH ---
	// Só funciona com int e char. (Não tente usar switch com string/texto!)
	switch (operacao) {
	case '+':
		resultado = n1 + n2;
		break; // OBRIGATÓRIO: Sem break, ele cai no case de baixo (Fall-through).

	case '-':
		resultado = n1 - n2;
		break;

	case '*':
		resultado = n1 * n2;
		break;

	case '/':
		// Tratamento de erro simples
		if (n2 == 0) {
			cout << "ERRO!: Nenhum numero pode ser dividido por 0." << endl;
			concluido = false;
			break; // Sai do switch
		}
		else {
			resultado = n1 / n2;
			break;
		}

	default: // Ocorre se a operação for inválida (ex: '%', '$')
		cout << "Operacao invalida." << endl;
		concluido = false;
		break;
	}

	if (concluido) {
		cout << "Resultado: " << resultado << endl;
	}
}