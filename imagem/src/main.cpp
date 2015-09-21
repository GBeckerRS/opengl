#include        <iostream>

#include        "inc/display.h"     // OpenGL
#include        "inc/imagem.h"
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
    img = new GBK::Imagem (400, 400);
    img->noise ();

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    return 0;
}

