#pragma once

#include <string>
class Pessoa {
private:
    std::string nome;
    int idade;
    double altura;
    int quantidadeDeIrmaos;
    std::string endereco;
public:
    Pessoa(std:: string name, int age, double height, int brothers, std::string address);

    void imprime_info() const;
    bool is_filho_unico() const;
};
