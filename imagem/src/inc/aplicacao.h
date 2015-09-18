#ifndef     APLICACAO_H
#define     APLICACAO_H

#include    "imagem.h"

namespace GBK
{
class Aplicacao
{
public:
    Aplicacao (Imagem& img);    

    Imagem* getImgTeste ();

private:
    Imagem* _imgTeste;
};
}

#endif      // APLICACAO_H

