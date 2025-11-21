#include "Node.h"

// --- DICA DE SINTAXE: IMPLEMENTAÇÃO DE CONSTRUTOR ---
// Node::Node -> "Estou implementando o construtor da classe Node"

// --- DICA DE PROVA: A IMPORTÂNCIA DO NULLPTR ---
// "proximo(nullptr)"
// Isso é VITAL. Quando você cria o vagão, o gancho dele não está ligado a nada.
// Se você esquecer de colocar "nullptr", o ponteiro vai apontar para um lixo de memória.
// Consequência: Quando seu 'while (temp != nullptr)' chegar no fim, ele não vai parar.
// Ele vai tentar acessar o lixo de memória e o programa vai travar (Crash).
// Sempre, SEMPRE inicialize ponteiros com nullptr se eles não tiverem dono ainda.



Node::Node(Processo* p) : processo(p), proximo(nullptr) {
    // Corpo vazio.
    // Obs: Não precisa de ponto e vírgula ";" depois de fechar chaves "}" em funções.
}