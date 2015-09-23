#ifndef         ARQUIVO_H
#define         ARQUIVO_H

namespace GBK
{
class Arquivo
{
public:
    Arquivo (char* nome, bool modo);
    ~Arquivo ();

    char* le ();
    unsigned long getTamanhoArquivo ();

private:
    char* _nome;
    bool _modo;

    char* _buffer;

    void limpaBuffer ();
};
}

#endif          // ARQUIVO_H
