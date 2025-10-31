#pragma once
#include <iostream>

template<class n>
void soma(n a, n b) {
	std::cout << (a + b) << std::endl;
}
template<class n>
void subtracao(n a, n b) {
	std::cout << (a - b) << std::endl;
}
template<class n>
void multiplicacao(n a, n b){
	std::cout << (a * b) << std::endl;
}
template<class n>
void divisao(n a, n b) {
	if (b == 0) {
		std::cout << "Nao existe divisao por 0" << std::endl;
	}
	else {
		std::cout << (a / b) << std::endl;
	}
}