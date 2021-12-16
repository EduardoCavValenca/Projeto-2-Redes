#ifndef RECEPTOR_H
#define RECEPTOR_H

#include <bitset>
#include <iostream>
#include <vector>

void Receptor(std::vector<bool> fluxoBrutoDeBits, int tipoDeControleDeErro);
void CamadaEnlaceDadosReceptora(std::vector<bool> quadro, int tipoDeControleDeErro);
std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErro(std::vector<bool> quadro, int tipoDeControleDeErro, bool* Erro);
std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(std::vector<bool> quadro, bool* Erro);
std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(std::vector<bool> quadro, bool* Erro);
std::vector<bool> CamadaEnlaceDadosReceptoraControleDeErroCRC(std::vector<bool> quadro, bool* Erro);
void CamadaDeAplicacaoReceptora(std::vector<bool> quadro, bool Erro);
void AplicacaoReceptora(std::string mensagem, bool Erro);

#endif
