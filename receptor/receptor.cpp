#include "receptor.h"

#include <numeric>

#include "../bitHandler/bitHandler.h"

void Receptor(std::vector<bool> fluxoBrutoDeBits, int tipoDeControleDeErro) {

    CamadaEnlaceDadosReceptora(fluxoBrutoDeBits,tipoDeControleDeErro);
}

void CamadaEnlaceDadosReceptora(std::vector<bool> quadro, int tipoDeControleDeErro) {
    bool Erro;
    std::vector<bool> mensagem;
    mensagem = CamadaEnlaceDadosReceptoraControleDeErro(quadro, tipoDeControleDeErro, &Erro);

    CamadaDeAplicacaoReceptora(mensagem, Erro);
}

std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErro(std::vector<bool> quadro, int tipoDeControleDeErro, bool* Erro) {    
    switch (tipoDeControleDeErro) {
        // Bit de paridade par
        case 0:
            // Adiciona bit de paridade par no final do quadro
            return CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro,Erro);
            break;
        // Bit de paridade impar
        case 1:
            // Adiciona bit de paridade impar no final do quadro
            return CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(quadro,Erro);
            break;
        // CRC-32
        case 2:
            // Adiciona o resto da divisao binaria modulo-2 no final do quadro
            return CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro,Erro);
            break;
    }
    return quadro;
}

std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(std::vector<bool> quadro, bool* Erro) {
    // Numero par de 1
    int countOne = std::accumulate(quadro.begin(), quadro.end(), 0);
    if (countOne % 2 == 0) {
        //Sem erros
        *Erro = false;
    } else {
        //Com erros
        *Erro = true;
    }

    quadro.pop_back();

    return quadro;
}

std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(std::vector<bool> quadro, bool* Erro) {
    // Numero impar de 1
    int countOne = std::accumulate(quadro.begin(), quadro.end(), 0);
    if (countOne % 2 == 0) {
        //Com erros
        *Erro = true;
    } else {
        //Sem erros
        *Erro = false;
    }
    
    quadro.pop_back();
    return quadro;
}

std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroCRC(std::vector<bool> quadro, bool* Erro) {
    // Usamos polinomio CRC-32 (IEEE 802):
    // G(x) = x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + 1
    // Em bits 100000100110000010001110110110111 
    // r = 33
    // r-1 = 32

    // Inicializando o divisor CRC-32
    std::vector<int> divisor{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    std::vector<bool> extra_dividendo, resto;

    // Inicializa o resto
    for (size_t i = 0; i < divisor.size(); i++) {
        resto.push_back(quadro[i]);
    }

    // O restante do quadro fica em extra_dividendo
    for (size_t i = divisor.size(); i < quadro.size(); i++) {
        extra_dividendo.push_back(quadro[i]);
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

    // Se o resto tiver todos os bits iguais a zero, entao nao houve erros na transmissao
    *Erro = false;
    for(size_t i = 0; i<resto.size(); i++) {
        if(resto[i]) {
            *Erro = true;
            break;
        }
    }

    // Retira os 32 ultimos bits do quadro para ficar somente a mensagem
    quadro.erase(quadro.end()-32,quadro.end());

    return quadro;
}


void CamadaDeAplicacaoReceptora(std::vector<bool> quadro, bool Erro) {
    // Convertendo bits para char
    print_bits(quadro);

    std::string mensagem = bits_to_string(quadro);
    // Chama proxima camada
    AplicacaoReceptora(mensagem, Erro);
}

void AplicacaoReceptora(std::string mensagem, bool Erro) {
    std::cout << "A mensagem recebida foi: " << mensagem << std::endl;

    if(Erro) {
        std::cout << "A mensagem possui erros!" << std::endl;
    }
    else {
        std::cout << "A mensagem nao possui erros!" << std::endl;
    }
}
