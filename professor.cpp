// Funcoes que o professor passo no PDF do trabalho
#include <iostream>

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora(std::string mensagem);
void AplicacaoReceptora(std::string mensagem);
void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[]);

int main() {
    AplicacaoTransmissora();
    return 0;
}

void AplicacaoTransmissora() {
    std::string mensagem;
    std::cout << "Digite uma mensagem:" << std::endl;
    std::cin >> mensagem;
    // Chama proxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
    // Em um exemplo mais realistico, aqui seria dado um SEND do SOCKET (?)
}

void CamadaDeAplicacaoTransmissora(std::string mensagem) {
    // int quadro[] = mensagem; //Trabalhar com bits!
    // Chama proxima camada
    //...
}

void CamadaEnlaceDadosTransmissora(int quadro[]) {
    CamadaEnlaceDadosTransmissoraControleDeErro(quadro);
    // Chama proxima camada
}

void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[]) {
    int tipoDeControleDeErro = 0;  // Alterar de acordo com o teste
    switch (tipoDeControleDeErro) {
        case 0:  // Bit de paridade par
            // codigo
            break;
        case 1:  // Bit de paridade impar
            // codigo
            break;
        case 2:  // CRC
            // codigo
            break;
    }
}

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[]) {
    // implementar algoritmo
}

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[]) {
    // implementar algoritmo
}

void CamadaEnlaceDadosTransmissoraControleDeErroCRC(int quadro[]) {
    // implementar algoritmo
    // Usar polinomio CRC-32 (IEEE 802)
}

void MeioDeComunicacao(int fluxoBrutoDeBits[]) {
    // OBS: trabalhar com BITS e nao com BYTES!
    int erro, porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];

    porcentagemDeErros = 0;  // 10%, 20%, 30%, ..., 100%
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        if ((rand() % 100 == ...)) {  // Fazer a probabilidade do erro
            fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;  // BITS!
        } else {  // ERRO! INVERTER (usa condicao ternaria)
            (fluxoBrutoDeBitsPontoB == 0)
                ? fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB++
                : fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB--;
        }
    }
}






















/*Receptor*/
void CamadaDeAplicacaoReceptora(int quadro[]) {
    // std::string mensagem = quadro[]; // Estava trabalhando com bits
    // Chama proxima camada
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(std::string mensagem) {
    std::cout << "A mensagem recebida foi: " << mensagem << std::endl;
}


