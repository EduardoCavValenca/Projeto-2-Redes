#include "meioDeComunicacao.h"

std::vector<bool> MeioDeComunicacao(std::vector<bool> fluxoBrutoDeBits) {
    // OBS: trabalhar com BITS e nao com BYTES!
    std::vector<bool> fluxoBrutoDeBitsFinal;
    float porcentagemErro = 0;
    size_t i = 0;

    while(fluxoBrutoDeBitsFinal.size() != fluxoBrutoDeBits.size()) {
        // Determina se mudamos o bit ou nao
        if ((rand() % 100) >= porcentagemErro) {
            // Nao muda o bit
            fluxoBrutoDeBitsFinal.push_back(fluxoBrutoDeBits[i]);
        } 
        else {  // ERRO! Inverter de 0 para 1 ou de 1 para 0
            fluxoBrutoDeBitsFinal.push_back(!fluxoBrutoDeBits[i]);
        }
        i++;
    }

    return fluxoBrutoDeBitsFinal;
}