#ifndef         DISPLAY_H
#define         DISPLAY_H

#include        <GL/gl.h>
#include        <GL/glu.h>
#include        <GL/glut.h>

namespace GBK
{
    void inicializa (int argc, char* argv[], int largura, int altura, int posX, int posY);
    void callbackDisplay (void);
    void callbackTeclado (unsigned char tecla, int x, int y);
}

#endif          // DISPLAY_H

