#ifndef         DISPLAY_H
#define         DISPLAY_H

#include        <GL/gl.h>
#include        <GL/glu.h>
#include        <GL/glut.h>

namespace unisinos
{
    void inicializa (int argc, char* argv[], int largura, altura);
    void callbackDisplay (void);
    void callbackTeclado (unsigned char key, int x, int y);
}

#endif          // DISPLAY_H

