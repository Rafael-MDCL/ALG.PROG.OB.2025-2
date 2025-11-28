#pragma once
#include "Processo.h"

class Node {
public:
    Processo* processo; 
    Node* proximo;      

    Node(Processo* p);
};