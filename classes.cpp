#include <iostream>
#include "header.h"
using namespace std;

//Implementação dos métodos da class Cliente
Cliente::Cliente(std::string nome, std::string cpf) : 
nome(nome), cpf(cpf){}
std::string Cliente::getNome() const {return nome;}
std::string Cliente::getCpf() const {return cpf;}

//Implementação dos métodos da class ContaBancaria
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo) : 
numero(numero), titular(titular), saldo(saldo){}
//Métodos públicos
int ContaBancaria::getNum(){
    return numero;
}
void ContaBancaria::depositar(double valor){
    saldo += valor;
}
void ContaBancaria::sacar(double valor){
    if(saldo >= valor){ //Verificação
        saldo -= valor;
    }else{
        std::cout << "Saldo insuficiente." << std::endl;
    }
}
//Sobrecarga do método Transferir
    void ContaBancaria::transferir(double valor, ContaBancaria &destino){
        if(saldo >= valor){ //Verificação
            saldo -= valor;
            destino.depositar(valor);
            std::cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.getNum() << std::endl;
        }else{
            std::cout << "Saldo insuficiente." << std::endl;
        }
    }
    //Transferir com 2 destinos
    void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
        if(saldo >= valor){ //Verificação
            saldo -= valor;
            destino1.depositar(valor/2);
            destino2.depositar(valor/2);
            std::cout << "Transferido: R$ " << valor << " para cada conta (" << destino1.getNum() << " e " << destino2.getNum() << ")" << " da conta " << numero << std::endl;
        }else{
            std::cout << "Saldo insuficiente." << std::endl;
        }
    }
void ContaBancaria::exibirSaldo(){
    std::cout << "Saldo atual da conta " << numero << ": " << saldo << std::endl;
}
void ContaBancaria::exibirInformacoes(){
    std::cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << std::endl;
    std::cout << "Numero da Conta: " << numero << ", Saldo: R$ " << saldo << std::endl;
}
