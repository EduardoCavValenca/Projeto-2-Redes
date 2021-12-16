#include "transmissor.h"

#include <numeric>

#include "../bitHandler/bitHandler.h"

std::vector<bool> Transmissor(int tipoDeControleDeErro){

    return AplicacaoTransmissora(tipoDeControleDeErro);

}

std::vector<bool> AplicacaoTransmissora(int tipoDeControleDeErro) {
    std::string a;
    std::getline (std::cin, a);
    
    std::string mensagem;
    std::cout << "Digite uma mensagem:" << std::endl;
    std::getline (std::cin,mensagem);


    // Chama proxima camada
    return CamadaDeAplicacaoTransmissora(mensagem, tipoDeControleDeErro);
}

std::vector<bool> CamadaDeAplicacaoTransmissora(std::string mensagem, int tipoDeControleDeErro) {
    // Convertendo mensagem para bits
    std::vector<bool> quadro = string_to_bits(mensagem);

    // Chama proxima camada
    return CamadaEnlaceDadosTransmissora(quadro, tipoDeControleDeErro);
}

std::vector<bool> CamadaEnlaceDadosTransmissora(std::vector<bool> quadro, int tipoDeControleDeErro) {

    return CamadaEnlaceDadosTransmissoraControleDeErro(quadro, tipoDeControleDeErro);
}

std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErro(std::vector<bool> quadro, int tipoDeControleDeErro) {
    switch (tipoDeControleDeErro) {
        // Bit de paridade par
        case 0:
            // Adiciona bit de paridade par no final do quadro
            return CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
            break;
        // Bit de paridade impar
        case 1:
            // Adiciona bit de paridade impar no final do quadro
            return CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro);
            break;
        // CRC-32
        case 2:
            // Adiciona o resto da divisao binaria modulo-2 no final do quadro
            return CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
            break;
    }
    return quadro;
}

std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(
    std::vector<bool> quadro) {
    // Numero par de 1, adiconar 0 ao final
    // Numero impar de 1, adiconar 1  ao final
    int countOne = std::accumulate(quadro.begin(), quadro.end(), 0);
    if (countOne % 2 == 0) {
        quadro.push_back(0);
    } else {
        quadro.push_back(1);
    }

    return quadro;
}

std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(
    std::vector<bool> quadro) {
    // Numero impar de 1, adicionar 0 no final
    // Numero par de 1, adicionar 1 no final
    int countOne = std::accumulate(quadro.begin(), quadro.end(), 0);
    if (countOne % 2 == 0) {
        quadro.push_back(1);
    } else {
        quadro.push_back(0);
    }
    
    return quadro;
}

std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroCRC(std::vector<bool> quadro) {
    // Usamos polinomio CRC-32 (IEEE 802):
    // G(x) = x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + 1
    // Em bits 100000100110000010001110110110111 
    // r = 33
    // r-1 = 32

    // Inicializando o divisor CRC-32
    std::vector<int> divisor{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    // Fazemos uma copia do quadro para futuras manipulacoes
    std::vector<bool> quadro_copia = quadro;

    // Adicionar r-1 = 32 zeros no final do quadro
    for (size_t i = 0; i < divisor.size() - 1; i++) {
        quadro_copia.push_back(false);
    }

    std::vector<bool> extra_dividendo, resto;

    // Inicializa o resto
    for (size_t i = 0; i < divisor.size(); i++) {
        resto.push_back(quadro_copia[i]);
    }

    // O restante do quadro fica em extra_dividendo
    for (size_t i = divisor.size(); i < quadro_copia.size(); i++) {
        extra_dividendo.push_back(quadro_copia[i]);
    }

    while (true) {
        if (resto[0]) {
            for (size_t i = 0; i < divisor.size(); i++) {
                resto[i] = (divisor[i] ^ resto[i]);
            }
        }

        if (extra_dividendo.size() != 0) {
            resto.erase(resto.begin());
            resto.push_back(extra_dividendo[0]);
            extra_dividendo.erase(extra_dividendo.begin());
        } else {
            break;
        }
    }

    // O primeiro bit do resto final nao nos interessa
    resto.erase(resto.begin());

    // Copia o resto para o final do quadro original
    for (size_t i = 0; i < resto.size(); i++) {
        quadro.push_back(resto[i]);
    }

    return quadro;
}
