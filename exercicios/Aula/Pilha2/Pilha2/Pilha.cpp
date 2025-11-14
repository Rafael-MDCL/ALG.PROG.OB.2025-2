#include "Pilha.h"
#include <iostream>

using namespace std;

Pilha::Pilha() {
	topo = nullptr;
}

void Pilha::push(char c) {
	node* novoTopo = new node;
	novoTopo->dado = c;
	novoTopo->abaixo = topo;
	topo = novoTopo;
}

char Pilha::pop() {
	if (topo == nullptr) {
	cout << "ERRO: Tentativa de pop em pilha vazia!" << endl;
	return '\0';
	}
	else {
		char temp;
		temp = topo->dado;
		node* antigo = topo;
		topo = topo->abaixo;
		delete antigo;
		return temp;
	}
}

bool Pilha::estaVazia() const {
	return (topo == nullptr);
}