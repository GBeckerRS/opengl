#include        <GL/gl.h>
#include        <GL/glu.h>
#include        <GL/glut.h>

#include        "inc/display.h"

void GBK::inicializa (int argc, char* argv[], int largura, int altura, int posX, int posY)
{
    // Inicializacoes OpenGL
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (largura, altura);
    glutInitWindowPosition (posX, posY);
    glutCreateWindow ("@#@");

    // Inicializacoes Glut
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0, largura, altura, 0.0, 0.0, 1.0);

    // Registra funcoes de callback
    glutDisplayFunc (GBK::callbackDisplay);
    glutKeyboardFunc (GBK::callbackTeclado);

    // Laco de execucao da glut
    glutMainLoop ();
}

void GBK::callbackDisplay (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glRasterPos2i (0,0);
    //glDrawPixels (this->getLargura (), this->getAltura (), GL_BRGA_EXT, GL_UNSIGNED_BYTE, image);
    glFlush ();
}

void GBK::callbackTeclado (unsigned char tecla, int x, int y)
{
    if( tecla == 'q' || tecla == 'Q')
    {
        exit(0);
    }
}

