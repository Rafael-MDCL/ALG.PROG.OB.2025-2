#include <iostream>
#include "Retangulo.h"
using namespace std;

int main() {
	Retangulo r1(5, 3);


	cout << "Base: " << r1.getBase() << endl;
	cout << "Altura: " << r1.getAltura() << endl;
		cout << "Area: " << r1.getArea() << endl;

	r1.setBase(10);
	r1.setAltura(4);

	cout << "\n Depois de alterar:" << endl;
	cout << "Base: " << r1.getBase() << endl;
	cout << "Altura: " << r1.getAltura() << endl;
	cout << "Area: " << r1.getArea() << endl;
	

	return 0;
}