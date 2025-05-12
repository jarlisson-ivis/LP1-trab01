#ifndef HEADER_H
#define HEADER_H
#include <string>

class Cliente {
    //Atributos privados
    private:
        std::string nome;
        std::string cpf;

    public:
        //Construtor
        Cliente(std::string nome, std::string cpf);
        //Métodos públicos
        std::string getNome() const;
        std::string getCpf() const;
};

class ContaBancaria {
    //Atributos privados
    private:
        int numero;
        Cliente titular;
        double saldo;


    public:
        //Construtor
        ContaBancaria(int numero, Cliente titular, double saldo = 0);
        //Métodos públicos
        int getNum();
        void depositar(double valor);
        void sacar(double valor);
        //Sobrecarga do método Transferir
            void transferir(double valor, ContaBancaria &destino);
            //Transferir com 2 destinos
            void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);
        void exibirSaldo();
        void exibirInformacoes();
};
#endif