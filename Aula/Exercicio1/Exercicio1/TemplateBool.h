#pragma once
#include <iostream>

template<class T>
void imprime(T a, T b) {
	std::cout << "a soma dos valores eh: " << a + b << std::endl;
}
template<>
void imprime<bool>(bool a, bool b) {
	std::cout << "O valor l�gico dos bools eh: " << (a || b) << std::endl;
}
