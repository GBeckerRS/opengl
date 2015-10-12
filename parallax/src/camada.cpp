#include    "camada.h"
#include    "imagem.h"

GBK::Camada::Camada (GBK::Imagem* img, int tx, int ty, int largura, int altura)
{
    this->_img = img;
    this->_tx = tx;
    this->_ty = ty;
    this->_larguraV = largura;
    this->_alturaV = altura;
}

GBK::Camada::~Camada ()
{
}

void GBK::Camada::setTX (int deslocamento)
{
    this->_tx = deslocamento;
}

void GBK::Camada::setTY (int deslocamento)
{
    this->_ty = deslocamento;
}

void GBK::Camada::setLargura (int largura)
{
    this->_larguraV = largura;
}

void GBK::Camada::setAltura (int altura)
{
    this->_alturaV = altura;
}

int GBK::Camada::getTX ()
{
    return this->_tx;
}

int GBK::Camada::getTY ()
{
    return this->_ty;
}

int GBK::Camada::getLargura ()
{
    return this->_larguraV;
}

int GBK::Camada::getAltura ()
{
    return this->_alturaV;
}

GBK::Imagem* GBK::Camada::getView (int x, int y)
{
    GBK::Imagem* img = this->_img->split (x, y, this->getLargura (), this->getAltura ());
    return img;
}

