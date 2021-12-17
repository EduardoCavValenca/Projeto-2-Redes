#include <iostream>
#include <bitset>
#include <vector>

#include "bitHandler/bitHandler.h"
#include "transmissor/transmissor.h"
#include "meioDeComunicacao/meioDeComunicacao.h"
#include "receptor/receptor.h"

int main() {
    // Permite selecionar o tipo de deteccao de erro utilizado
    std::cout << "Escolha modo de controle de erro:" << std::endl;
    std::cout << "0: Bit de paridade par" << std::endl;
    std::cout << "1: Bit de paridade impar" << std::endl;
    std::cout << "2: CRC-32" << std::endl;
    int tipoDeControleDeErro;
    std::cin >> tipoDeControleDeErro;

    // Parte principal do programa
    //Vetor de bits
    std::vector<bool> mensagem;  

    // Transmissor recebe mensagem do usuario e retorna em bits
    mensagem = Transmissor(tipoDeControleDeErro);
    std::cout << "Mensagem original:" << std::endl;
    print_bits(mensagem);
    
    // Mensagem passa pelo meio de comunicacao sujeita a erros
    mensagem = MeioDeComunicacao(mensagem);
    std::cout << "Mensagem apos meio de comunicacao:" << std::endl;
    print_bits(mensagem);

    // Receptor identifica erro e exibe mensagem final
    Receptor(mensagem, tipoDeControleDeErro);
    return 0;
}
