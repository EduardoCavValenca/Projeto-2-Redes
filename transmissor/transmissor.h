#ifndef TRANSMISSOR_H
#define TRANSMISSOR_H

#include <bitset>
#include <iostream>
#include <vector>

std::vector<bool> Transmissor(int tipoDeControleDeErro);
std::vector<bool> AplicacaoTransmissora(int tipoDeControleDeErro);
std::vector<bool> CamadaDeAplicacaoTransmissora(std::string mensagem, int tipoDeControleDeErro);
std::vector<bool> CamadaEnlaceDadosTransmissora(int quadro[], int tipoDeControleDeErro);
std::vector<bool> CamadaEnlaceDadosTransmissora(std::vector<bool> quadro, int tipoDeControleDeErro);
std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErro(std::vector<bool> quadro, int tipoDeControleDeErro);
std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(std::vector<bool> quadro);
std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(std::vector<bool> quadro);
std::vector<bool> CamadaEnlaceDadosTransmissoraControleDeErroCRC(std::vector<bool> quadro);

#endif