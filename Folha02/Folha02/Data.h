#pragma once
#include  <string>

using namespace std;

class Data {
protected:
	int dia;
	int mes;
	int ano;

public:
	Data(int dia, int mes, int ano);

	void setDia(int DD);
	void setMes(int MM);
	void setAno(int AAAA);

	int getAno() const;
	int getMes() const;
	int getDia() const;

	void imprime_data();
};