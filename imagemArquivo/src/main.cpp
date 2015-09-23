#include        <iostream>
#include        <cstring>

#include        "arquivo.h"

int main (void)
{
    char* pcTexto = new char[10];
    pcTexto = strcpy (pcTexto, "teste.txt");
    GBK::Arquivo arq (pcTexto, 0);
    std::cout << "Tamanho arquivo: " << arq.getTamanhoArquivo () << std::endl;
    char* conteudo = arq.le ();
    std::cout << "Conteudo: " << conteudo << std::endl;

    return 0;
}
