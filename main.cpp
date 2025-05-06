#include <iostream>
#include <string>
using namespace std;

class Cliente {
    //Atributos privados
    private:
        std::string nome;
        std::string cpf;

    public:
        //Construtor
        Cliente(std::string nome, std::string cpf) : 
        nome(nome), cpf(cpf){};
        //Métodos públicos
        std::string getNome() const {return nome;}
        std::string getCpf() const {return cpf;}
};

class ContaBancaria {
    //Atributos privados
    private:
        int numero;
        double saldo;
        Cliente titular;

    public:
        //Construtor
        ContaBancaria(int numero, Cliente titular, double saldo = 0) : 
        numero(numero), titular(titular), saldo(saldo){};
        //Métodos públicos
        int getNum(){
            return numero;
        }
        void depositar(double valor){
            saldo += valor;
        }
        void sacar(double valor){
            if(saldo >= valor){ //Verificação
                saldo -= valor;
            }else{
                std::cout << "Saldo insuficiente." << std::endl;
            }
        }
        //Sobrecarga do método Transferir
            void transferir(double valor, ContaBancaria &destino){
                if(saldo >= valor){ //Verificação
                    saldo -= valor;
                    destino.depositar(valor);
                    std::cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.getNum() << std::endl;
                }else{
                    std::cout << "Saldo insuficiente." << std::endl;
                }
            }
            //Transferir com 2 destinos
            void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
                if(saldo >= valor){ //Verificação
                    saldo -= valor;
                    destino1.depositar(valor/2);
                    destino2.depositar(valor/2);
                    std::cout << "Transferido: R$ " << valor << " para cada conta (" << destino1.getNum() << " e " << destino2.getNum() << ")" << " da conta " << numero << std::endl;
                }else{
                    std::cout << "Saldo insuficiente." << std::endl;
                }
            }
        void exibirSaldo(){
            std::cout << "Saldo atual da conta " << numero << ": " << saldo << std::endl;
        }
        void exibirInformacoes(){
            std::cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << std::endl;
            std::cout << "Numero da Conta: " << numero << ", Saldo: R$ " << saldo << std::endl;
        }
};

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}