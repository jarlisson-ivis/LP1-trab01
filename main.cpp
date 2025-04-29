#include <iostream>
#include <string>
using namespace std;

class Cliente {
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
    private:
        int numero;
        double saldo;
        Cliente titular;

    public:
        //Construtor
        ContaBancaria(int numero, Cliente titular, double saldo = 0) : 
        numero(numero), titular(titular), saldo(saldo){};
        //Métodos públicos
        void depositar(double valor){
            //depositar valor na conta
        }
        void sacar(double valor){
            //sacar valor na conta
            //verifique se há saldo suficiente
        }
        //Sobrecarga do método Transferir
            void transferir(double valor, ContaBancaria &destino){
                //transferir para outra conta
                //verifique se há saldo suficiente
            }
            void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
                //transferir e dividir igualmente entre duas contas
                //verifique se há saldo suficiente
            }
        void exibirSaldo(){
            std::cout << "Titular: " << titular.getNome() << std::endl;
            std::cout << "Numero: << std::endl;
            std::cout << std::endl;
        }
        void exibirInformacoes(){

        }
};

int main() {
    std::cout << "Iniciando..." << std::endl;

    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    //para fins de teste
    std::cout << cliente1.getNome() << " - " << cliente1.getCpf() << std::endl;
    std::cout << cliente2.getNome() << " - " << cliente2.getCpf() << std::endl;
    std::cout << cliente3.getNome() << " - " << cliente3.getCpf() << std::endl;

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    //para fins de teste
    std::cout << c1.getNome() << " - " << cliente1.getCpf() << std::endl;

    // Exibe o saldo inicial da conta de Ana
    /*conta1.exibirSaldo();*/

    // Ana transfere R$200 para Bruno
    /*conta1.transferir(200.0, conta2);*/

    // Ana transfere R$300 divididos entre Bruno e Carla
    /*conta1.transferir(300.0, conta2, conta3);*/

    // Exibição dos saldos finais
    /*cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();*/

    return 0;
}
