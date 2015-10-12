#ifndef     IMAGEM_H
#define     IMAGEM_H

namespace GBK
{
class Imagem
{
public:
    Imagem (int largura, int altura);

    void setPixel (int argb, int x, int y);
    int getPixel (int x, int y);
    int getLargura ();
    int getAltura ();
    int* getPixels ();

    void noise ();
    void empacotaPixel (int a, int r, int g, int b, int* argb);
    void desempacotaPixel (int argb, int* a, int* r, int* g, int* b);
    void plot (GBK::Imagem* img);
    Imagem* split (int x, int y, int largura, int altura);

private:
    int* _pixels;
    int _largura;
    int _altura;

    // Métodos privados
    int getPosicao (int x, int y);
};
}

#endif      // IMAGEM_H
