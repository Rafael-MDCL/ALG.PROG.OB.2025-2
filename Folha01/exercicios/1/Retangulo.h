#pragma once
#include <stdexcept>

class Retangulo {
	// Atributos
	private:
	double base;
	double altura;
public:
	// Construtor
	Retangulo(double base, double altura);

	// Getters
	double getBase() const;
	double getAltura() const;
	double getArea() const;

	// Setters
	void setBase(double b);
	void setAltura(double h);
};
