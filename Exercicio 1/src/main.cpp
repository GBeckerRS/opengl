#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

#include    "inc/formas.h"

#define PI 3.1415926535898
unsigned char tecla;

void drawScene (void)
{
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    if (tecla == 'e')
    {
        elipse ();
    }
    else
    {
        if (tecla == 'p')
        {
            poligono ();
        }
        else
        {
            if (tecla == 'c')
            {
                circunferencia ();
            }
            else
            {
                if (tecla == 'o')
                {
                    circulo ();
                }
                else
                {
                    if (tecla == 'r')
                    {
                        referencia ();
                    }
                    else
                    {
                        if (tecla == 'a')
                        {
                            arco ();
                        }
                        else
                        {
                            if (tecla == 'n')
                            {
                                arcoPreenchido ();
                            }
                            else
                            {
                                if (tecla == 'z')
                                {
                                    fatiaPizza ();
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    glFlush ();
}

void keyboard (unsigned char key, int x, int y)
{
    if (key == 'q' or key == 'Q')
    {
        exit (0);
    }
    tecla = key;

    glutPostRedisplay ();
}

void inicializa ()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0f, 400, 400, 0.0f, 0.0f, 1.0f);
}

int main (int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (400, 400);
    glutCreateWindow("Primeiro exemplo OpenGL");

    // inicializações e definições constantes
    inicializa();

    // Define funções de callback
    glutKeyboardFunc (keyboard);
    glutDisplayFunc (drawScene);

    glutMainLoop();

    return 0;
}

