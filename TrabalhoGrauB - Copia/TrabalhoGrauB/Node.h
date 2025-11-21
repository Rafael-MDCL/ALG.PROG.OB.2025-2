#pragma once
#include "Processo.h"

// DICA DE PROVA:
// Por que 'class' e 'public'?
// Poderíamos usar 'struct' (onde tudo já nasce público), que é o padrão para Nós.
// Como usamos 'class', precisamos colocar "public:" explicitamente.
// Se esquecer o "public", a FilaDeProcessos NÃO CONSEGUE acessar o 'proximo' nem o 'processo'.
class Node {
public:
    // --- DICA DE OURO: POR QUE PONTEIROS? ---

    // 1. Processo* (Payload/Carga):
    // Tem que ser ponteiro (*) por dois motivos:
    //    A) Tamanho: Processo é abstrato, não tem tamanho fixo.
    //    B) Polimorfismo: Só com ponteiros conseguimos guardar Computing, Writing, etc.
    //       na mesma variável. Se fosse objeto fixo, perderíamos os dados dos filhos.
    Processo* processo;

    // 2. Node* (Link/Elo):
    // Tem que ser ponteiro (*) porque é uma estrutura RECURSIVA.
    // Se você colocasse "Node proximo;" (sem *), o Node teria um Node dentro dele,
    // que teria outro Node dentro... criando um tamanho infinito (Stack Overflow).
    // Com ponteiro, guardamos apenas o ENDEREÇO do próximo (tamanho fixo).
    Node* proximo;

    // Construtor: Recebe a carga para guardar
    Node(Processo* p);
};