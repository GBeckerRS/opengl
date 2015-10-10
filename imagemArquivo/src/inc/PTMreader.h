#ifndef         PTMREADER_H
#define         PTMREADER_H

#include    <sstream>
#include    <string>

#include    "arquivo.h"
#include    "imagem.h"

namespace GBK
{
class PTMreader
{
public:
    PTMreader (std::string arquivo);
    GBK::Imagem* getImagem();

private:
    std::stringstream buffer;
    GBK::Arquivo* arq;

    void leArquivo ();
};
}

#endif          // PTMREADER_H

