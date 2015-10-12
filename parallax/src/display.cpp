#include        <GL/gl.h>
#include        <GL/glu.h>
#include        <GL/glut.h>

#include        "inc/display.h"
#include        "inc/gbkcallbacks.h"

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
    glutDisplayFunc (GBK::CALLBACKS::render);
    glutKeyboardFunc (GBK::CALLBACKS::teclado);

    // Laco de execucao da glut
    glutMainLoop ();
}

