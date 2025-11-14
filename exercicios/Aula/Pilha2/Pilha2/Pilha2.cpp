#include "Pilha.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Pilha pilha;
	string c;
	int tamanho;
	while (true) {
		cout << "Digite a linha" << endl;
		getline(cin, c);

		tamanho = c.length();
		for (int i = 0; i < tamanho; i++) {
			char caractereAtual = c[i];
			if (caractereAtual == '(' || caractereAtual == '[' || caractereAtual == '{') {
				pilha.push(caractereAtual);
			}
			else if (caractereAtual == ')' || caractereAtual == ']' || caractereAtual == '}') {
				if (pilha.estaVazia()) {
					cout << "Isso eh um erro" << endl;
					break;
				}
				else {

				}
			}
			
		}
	}
}
