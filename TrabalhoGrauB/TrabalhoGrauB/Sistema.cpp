#include "Sistema.h"
#include "FilaDeProcessos.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "ComputingProcess.h"
#include "Node.h"
#include "Processo.h"
#include "WritingProcess.h"

#include <iostream>

using namespace std;

Sistema::Sistema() : pidContador(1) {}

void Sistema::criarProcessos() {
    int escolha;
    float n1, n2;
    char op;
    cout << "--- Criar Processo ---" << endl;
    cout << "1. Computing Process (Calculo)" << endl;
    cout << "2. Writing Process (Gravacao)" << endl;
    cout << "3. Reading Process (Leitura)" << endl;
    cout << "4. Printing Process (Impressao)" << endl;
    cout << "Escolha: ";
    cin >> escolha;

    switch (escolha) {
    case 1:
        cout << "Digite a expressao (ex: 2 + 2) (obs: para multiplicacoes use '*'.) " << endl;
        cin >> n1 >> op >> n2;
        fila.adicionar(new ComputingProcess(pidContador, n1, op, n2));

        pidContador++;

        break;
    case 2:
        cout << "Digite a expressao para gravar (ex: 10 * 5): " << endl;
        cin >> n1 >> op >> n2;
        fila.adicionar(new WritingProcess(pidContador, n1, op, n2));
        
        pidContador++;

        break;
    case 3:
        fila.adicionar(new ReadingProcess(pidContador, fila));
        
        pidContador++;
        
        break;

    case 4:
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
        cout << "\n=== SISTEMA DE PROCESSOS ===" << endl;
        cout << "1. Criar Processo" << endl;
        cout << "2. Executar Proximo" << endl;
        cout << "3. Executar Processo Especifico" << endl;
        cout << "4. Salvar Fila (Em breve)" << endl;
        cout << "5. Carregar Fila (Em breve)" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha: ";
        if (!(cin >> opcao)) {
            cout << "Erro: Digite apenas numeros!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcao) {
        case 1:
           
            criarProcessos();
            break;

        case 2:
        
            cout << "Executando o proximo..." << endl;
            fila.executarProx();
            break;

        case 3:

            int pidAlvo;
            cout << "Digite o PID do processo a executar: ";
            cin >> pidAlvo;
            fila.executarEspecif(pidAlvo);
            break;

        case 4:
            fila.salvarEmArquivo("dados.txt");
            cout << "Fila salva com sucesso." << endl;
            break;

        case 5:
            fila.carregarDeArquivo("dados.txt");
            cout << "Fila carregada com sucesso." << endl;
            break;

        case 6:
            cout << "Saindo do sistema..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
    }
}