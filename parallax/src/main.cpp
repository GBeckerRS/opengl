#include        <iostream>
#include        <cstring>
#include        <GL/glut.h>

#include        "inc/display.h"
#include        "inc/imagem.h"
#include        "inc/PTMreader.h"
#include        "inc/gbkcallbacks.h"
#include        "inc/camada.h"

GBK::Imagem* img = 0;
GBK::Imagem* bg = 0;
int xCamada = 0;
int yCamada = 0;

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
    else
    {
        if ( tecla == 'd' || tecla == 'D')
        {
            xCamada += 4;
            if ((xCamada + 400) > 1200)
            {
                xCamada = 1200 - 400;
            }
        }
        else
        {
            if (tecla == 'a' || tecla == 'A')
            {
                xCamada -= 4;
                if (xCamada < 0)
                {
                    xCamada = 0;
                }
            }
        }
        delete img;
        img = bg->split (xCamada, yCamada, 400, 400);
    }
    glutPostRedisplay ();
}

int main (int argc, char* argv[])
{
    char* back = new char[15];
    strcpy (back, "bg.PTM");
    GBK::PTMreader ptm1 (back);
    bg = ptm1.getImagem ();

    img = bg->split (xCamada, yCamada, 400, 400);

    GBK::inicializa (argc, argv, 400, 400, 100, 100);

    delete img;
    img = 0;
    delete bg;
    bg = 0;
    delete back;
    back = 0;
    return 0;
}

