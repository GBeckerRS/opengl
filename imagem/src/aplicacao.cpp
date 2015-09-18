#include        "inc/aplicacao.h"

GBK::Aplicacao::Aplicacao (Imagem& img)
{
    this->_imgTeste = new GBK::Imagem (img.getLargura (), img.getAltura ());
}

