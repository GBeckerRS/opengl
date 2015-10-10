#include        <iostream>
#include        <cstring>

#include        "inc/display.h"     // OpenGL
#include        "inc/imagem.h"
#include        "PTMreader.h"
#include        "inc/gbkcallbacks.h"

GBK::Imagem* img = 0;

void GBK::CALLBACKS::render (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glDrawPixels (img->getLargura (), img->getAltura (), GL_BGRA_EXT, GL_UNSIGNED_BYTE, img->getPixels ());
    glFlush ();
}

void GBK::CALLBACKS::teclado (unsigned char tecla, int tapPosX, int tapPosY)
{
    if( tecla == 'q' || tecla == 'Q')
    {
        exit(0);
    }
}

int main (int argc, char* argv[])
{
    char* arq = new char[15];
    strcpy (arq, "blue.PTM");
    GBK::PTMreader ptm (arq);

    char* arq1 = new char[15];
    strcpy (arq1, "yellow.PTM");
    GBK::PTMreader ptm1 (arq1);
    GBK::Imagem* img1 = ptm1.getImagem ();

    char* arq2 = new char[15];
    strcpy (arq2, "red.PTM");
    GBK::PTMreader ptm2 (arq2);
    GBK::Imagem* img2 = ptm2.getImagem ();

    img = ptm.getImagem ();
    img->plot (img1);
    img->plot (img2);

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    delete[] arq;
    arq = 0;
    return 0;
}

