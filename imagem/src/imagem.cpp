#include    "inc/imagem.h"

#include    <stdlib.h>  // rand, srand
#include    <time.h>    // time,

#include    <iostream>  // std::cout

GBK::Imagem::Imagem (int largura, int altura)
{
    this->_largura = largura;
    this->_altura = altura;
    this->_pixels = new int[largura*altura];
}

void GBK::Imagem::setPixel (int argb, int x, int y)
{
    this->_pixels [x+(y*this->_largura)] = argb;
}

int GBK::Imagem::getPixel (int x, int y)
{
    return this->_pixels [x+(y*this->_largura)];
}

int GBK::Imagem::getLargura ()
{
    return this->_largura;
}

int GBK::Imagem::getAltura ()
{
    return this->_altura;
}

int* GBK::Imagem::getPixels ()
{
    return this->_pixels;
}

void GBK::Imagem::noise ()
{
    // inicializa a semente
    srand (time(NULL));

    int largura = this->getLargura ();
    int altura = this->getAltura ();
    for (int py = 0; py < altura; py++)
    {
        for (int px = 0; px < largura; px++)
        {
            int a = 255;
            int r = rand () % 255;
            int g = rand () % 255;
            int b = rand () % 255;
            int argb = 0;
            this->empacotaPixel (a, r, g, b, &argb);
            this->setPixel (argb, px, py);
        }
    }
}

void GBK::Imagem::empacotaPixel (int a, int r, int g, int b, int*  argb)
{
    *argb = (a << 24) | (r << 16) | (g << 8) | b;
}

void GBK::Imagem::desempacotaPixel (int argb, int* a, int* r, int* g, int* b)
{
    *a = (argb >> 24) & 0xff;
    *r = (argb >> 16) & 0xff;
    *g = (argb >> 8) & 0xff;
    *b = argb & 0xff;
}

void GBK::Imagem::plot (GBK::Imagem* img)
{
    float alphaCalculado = 0.0;
    int pX = 0, pY = 0;
    int a = 0, r = 0, g = 0, b = 0, aI = 0, rI = 0, gI = 0, bI = 0;
    int argb = 0, argbI = 0;
    int tamanho = this->_largura * this->_altura;
    for (int i = 0; i < tamanho; i++)
    {
        pX = i % this->_largura;
        pY = i / this->_largura;
        argb = this->getPixel (pX, pY);
        argbI = img->getPixel (pX, pY);
        this->desempacotaPixel (argb, &a, &r, &g, &b);
        img->desempacotaPixel (argbI, &aI, &rI, &gI, &bI);
        alphaCalculado = aI / 255;
        r = r * (1 - alphaCalculado) + rI * alphaCalculado;
        g = g * (1 - alphaCalculado) + gI * alphaCalculado;
        b = b * (1 - alphaCalculado) + bI * alphaCalculado;
        this->empacotaPixel (a, r, g, b, &argb);
        this->setPixel (argb, pX, pY);
    }
}

