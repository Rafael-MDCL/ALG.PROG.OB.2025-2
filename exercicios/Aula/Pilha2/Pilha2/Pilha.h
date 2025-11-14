#pragma once

class Pilha {
private:
	struct node {
		char dado;
		node* abaixo;
	};
	node* topo;
public:
	Pilha();

	void push(char c);
	char pop();
	bool estaVazia() const;
};