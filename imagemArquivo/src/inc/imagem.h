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

private:
    int* _pixels;
    int _largura;
    int _altura;
};
}

#endif      // IMAGEM_H
