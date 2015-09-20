#include        <iostream>

#include        "inc/display.h"     // OpenGL
#include        "inc/imagem.h"
#include        "inc/gbkcallbacks.h"

void GBK::CALLBACKS::render (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glRasterPos2i (0,0);
    //glDrawPixels (this->getLargura (), this->getAltura (), GL_BRGA_EXT, GL_UNSIGNED_BYTE, image);
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
    GBK::Imagem* img = new GBK::Imagem (10, 10);
    img->noise ();

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    return 0;
}

