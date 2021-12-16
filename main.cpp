#include <iostream>
#include <bitset>
#include <vector>

#include "bitHandler/bitHandler.h"
#include "transmissor/transmissor.h"
#include "meioDeComunicacao/meioDeComunicacao.h"
#include "receptor/receptor.h"

int main() {
    std::cout << "Escolha modo de controle de erro:" << std::endl;
    std::cout << "0: Bit de paridade par" << std::endl;
    std::cout << "1: Bit de paridade impar" << std::endl;
    std::cout << "2: CRC-32" << std::endl;

    int tipoDeControleDeErro;
    std::cin >> tipoDeControleDeErro;

    std::vector<bool> mensagem; //Vetor de bits 

    mensagem = Transmissor(tipoDeControleDeErro);
    print_bits(mensagem);
    mensagem = MeioDeComunicacao(mensagem);
    print_bits(mensagem);
    Receptor(mensagem, tipoDeControleDeErro);
    return 0;
}
