#include "Retangulo.h"

// Construtor
Retangulo::Retangulo(double b, double h) {
	if (b <= 0 || h <= 0) {
		throw std::invalid_argument("Base e altura devem ser maiores que zero");
	}
	base = b;
	altura = h;
}

// Getters

double Retangulo::getBase() const {
	return base;
}

double Retangulo::getAltura() const {
	return altura;
}

double Retangulo::getArea() const {
	return base * altura;
}

// Setters

void Retangulo::setBase(double b) {
	base = b;
}
void Retangulo::setAltura(double h) {
	altura = h;
}