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
    strcpy (arq, "bg.PTM");
    GBK::PTMreader ptm (arq);

    GBK::Imagem* img1 = ptm.getImagem ();
    img = img1->split (900, 100, 400, 100);

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    delete[] arq;
    arq = 0;
    return 0;
}

