#pragma once

class PilhaDePratos {
private:
	int quantidade;
public:
	PilhaDePratos();

	void push(int quantidade);
	void pop(int quantidade);
	int getQuantidade() const;
};