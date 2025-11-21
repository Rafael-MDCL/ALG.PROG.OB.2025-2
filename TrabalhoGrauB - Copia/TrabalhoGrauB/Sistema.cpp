#include "Sistema.h"
// OBRIGATÓRIO: Incluir TODAS as classes de processos filhos.
// Por quê? O Sistema funciona como uma "Fábrica". Para dar 'new' num ComputingProcess,
// ele precisa conhecer a definição (o .h) dessa classe.
#include "FilaDeProcessos.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "ComputingProcess.h"
#include "Node.h"
#include "Processo.h"
#include "WritingProcess.h"

// Necessário para usar numeric_limits no tratamento de erro do cin
#include <limits> 
#include <iostream>

using namespace std;

// Inicializa o contador em 1. Assim o primeiro processo terá PID 1.
Sistema::Sistema() : pidContador(1) {}

// --- MÉTODO FÁBRICA (FACTORY) ---
// Este método decide qual objeto criar baseado na escolha do usuário.
void Sistema::criarProcessos() {
    int escolha;
    float n1, n2;
    char op;

    cout << "--- Criar Processo ---" << endl;
    // ... (couts do menu) ...
    cout << "Escolha: ";
    cin >> escolha;

    switch (escolha) {
    case 1: // Computing
        cout << "Digite a expressao (ex: 2 + 2): " << endl;
        cin >> n1 >> op >> n2;

        // --- DICA DE PROVA: O USO DO 'NEW' ---
        // Por que "new ComputingProcess(...)" e não apenas "ComputingProcess c(...)"?
        // 1. Vida Útil: Se criar sem 'new', o objeto morre assim que chegar no 'break'.
        // 2. Polimorfismo: A fila espera um ponteiro (Processo*). O 'new' retorna um ponteiro.
        // 3. Memória: O 'new' aloca na memória Heap (permanente até dar delete).
        fila.adicionar(new ComputingProcess(pidContador, n1, op, n2));

        pidContador++; // Prepara o ID para o próximo
        break;

    case 2: // Writing
        cout << "Digite a expressao para gravar (ex: 10 * 5): " << endl;
        cin >> n1 >> op >> n2;
        fila.adicionar(new WritingProcess(pidContador, n1, op, n2));

        pidContador++;
        break;

    case 3: // Reading
        // --- DICA DE PROVA: PASSANDO A FILA ---
        // O ReadingProcess precisa adicionar coisas na fila.
        // Como estamos DENTRO do Sistema (que tem a fila), passamos o atributo 'fila' direto.
        fila.adicionar(new ReadingProcess(pidContador, fila));

        pidContador++;
        break;

    case 4: // Printing
        // Mesma lógica: passamos a fila para ele poder percorrê-la e imprimir.
        fila.adicionar(new PrintingProcess(pidContador, fila));

        pidContador++;
        break;

    default:
        cout << "Processo invalido! Selecione uma das opcoes validas." << endl;
        break;
    }
}

void Sistema::Menu() {
    int opcao = 0;

    while (opcao != 6) {
        // ... (couts do menu principal) ...
        cout << "Escolha: ";

        // --- DICA DE PROVA: PROTEÇÃO CONTRA LOOP INFINITO ---