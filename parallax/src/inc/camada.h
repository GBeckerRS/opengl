#ifndef     CAMADA_H
#define     CAMADA_H

#include    "imagem.h"

namespace GBK
{
class Camada
{
public:
    Camada (GBK::Imagem* img, int tx, int ty, int largura, int altura);
    ~Camada ();

    void setTX (int deslocamento);
    void setTY (int deslocamento);
    void setLargura (int largura);
    void setAltura (int altura);
    int getTX ();
    int getTY ();
    int getLargura ();
    int getAltura ();
    Imagem* getView (int x, int y);

private:
    int _tx, _ty;
    int _larguraV, _alturaV;    // Altura e largura da view da camada
    GBK::Imagem* _img;
};
}

#endif      // CAMADA_H

