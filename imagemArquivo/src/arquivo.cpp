#include        "arquivo.h"

#include        <fstream>
#include        <cstring>

GBK::Arquivo::Arquivo (char* nome, bool modo)
{
    int tam = strlen ((const char*)nome);
    this->_nome= new char[tam];
    this->_nome= strcpy (this->_nome, nome);
    this->_modo = modo;
}

GBK::Arquivo::~Arquivo ()
{
    if (this->_nome)
    {
        delete this->_nome;
        this->_nome = 0;
    }
    this->limpaBuffer ();
}

char* GBK::Arquivo::le ()
{
    long tam = this->getTamanhoArquivo ();
    if (tam == 0)
    {
        return 0;
    }
    std::ifstream input (this->_nome, std::ifstream::binary);
    this->limpaBuffer ();
    if (input)
    {
        this->_buffer = new char[tam];
        // Le os dados do arquivo
        input.read (this->_buffer, tam);
        input.close ();
    }
    return this->_buffer;
}

unsigned long GBK::Arquivo::getTamanhoArquivo ()
{
    long tam = 0;
    std::ifstream input (this->_nome, std::ifstream::binary);
    if (input)
    {
        input.seekg (0, input.end);
        tam = input.tellg ();
        input.seekg (0,input.beg);
        input.close ();
    }

    return tam;
}

void GBK::Arquivo::limpaBuffer ()
{
    if (this->_buffer)
    {
        delete this->_buffer;
        this->_buffer = 0;
    }
}

