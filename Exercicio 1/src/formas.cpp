#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

#include    "inc/formas.h"

#define PI 3.1415926535898

void poligono ()
{
    glColor3f (0.0, 0.0, 1.0);
    // Inicia o bloco do desenho da primitiva
    glBegin(GL_POLYGON);
        // Vertices do poligono
        glVertex3f (150.0, 150.0, 0.0); // v1
        glVertex3f (250.0, 150.0, 0.0); // v2
        glVertex3f (300.0, 250.0, 0.0); // v3
        glVertex3f (100.0, 250.0, 0.0); // v4
    // Finaliza o bloco do desenho da primitiva
    glEnd ();
}

void circulo ()
{
    // Cor do circulo
    glColor3f (0.0, 1.0, 1.0);
    // Quantidade de pontos do circulo
    GLfloat qtPontos = 50.0;
    // Angulo de cada ponto do circulo
    GLfloat angulo = 0.0;
    // Tamanho do circulo (raio*2 = diametro)
    GLfloat raio = 100.0;
    // Inicia o bloco do desenho da primitiva
    glBegin (GL_TRIANGLE_FAN);
        for (int i = 0; i < qtPontos; i++)
        {
            // Calculo do angulo relativo ao ponto desejado
            angulo = 2 * PI * i / qtPontos;
            // Cria o vértice
            glVertex2f ((cos(angulo) * raio)+200, (sin(angulo) * raio)+200);
        }
    // Finaliza o bloco do desenho da primitiva
    glEnd ();
}

void circunferencia ()
{
    // Cor da circunferencia
    glColor3f (0.0,1.0,0.0);
    // Largura do traco
    glLineWidth (10.0);
    // Quantidade de pontos da circunferencia
    GLfloat circle_points = 50;
    // Angulo de cada ponto
    GLfloat angle = 0.0f;
    // Tamanho da circunferencia (raio*2 = diametro)
    GLfloat raio = 100.0;
    // Inicia o bloco do desenho da primitiva
    glBegin (GL_LINE_LOOP);
        for (int i = 0; i < circle_points; i++)
        {
            // Calculo do angulo relativo ao ponto desejado
            angle = 2 * PI * i / circle_points;
            // Cria o vértice
            glVertex2f ((cos(angle) * raio)+200, (sin(angle) * raio)+200);
        }
    // Finaliza o bloco do desenho da primitiva
    glEnd ();
}

void elipse ()
{
    // Define a cor da elipse
    glColor3f (1.0,0.0,0.0);
    // Tamanho da largura do traco
    glLineWidth (10.0);
    // Quantidade de pontos da elipse
    GLfloat circle_points = 50;
    // Angulo de cada ponto da elipse
    GLfloat angle = 0.0f;
    // Tamanho da elipse no eixo x (raio*2 = diametro)
    GLfloat raioX = 50.0;
    // Tamanho da elipse no eixo y (raio*2 = diametro)
    GLfloat raioY = 100.0;
    // Inicia o bloco do desenho da primitiva
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < circle_points; i++)
        {
            // Calculo do angulo relativo ao ponto desejado
            angle = (2 * PI) * (i / circle_points);
            // Cria o vértice
            glVertex2f ((cos(angle)*raioX)+200, (sin(angle)*raioY)+200);
        }
    // Finaliza o bloco do desenho da primitiva
    glEnd();
}

void arco ()
{
    // Cor da circunferencia
    glColor3f (0.0,1.0,0.0);
    // Largura do traco
    glLineWidth (10.0);
    // Quantidade de pontos da circunferencia
    GLfloat circle_points = 50;
    // Angulo de cada ponto
    GLfloat angle = 0.0f;
    // Tamanho da circunferencia (raio*2 = diametro)
    GLfloat raio = 100.0;
    // Inicia o bloco do desenho da primitiva
    glBegin (GL_LINE_LOOP);
        for (int i = 0; i < (circle_points/2); i++)
        {
            // Calculo do angulo relativo ao ponto desejado
            angle = 2 * PI * i / circle_points;
            // Cria o vértice
            glVertex2f ((cos(angle) * raio)+200, (sin(angle) * raio)+200);
        }
    // Finaliza o bloco do desenho da primitiva
    glEnd ();
}

void fatiaPizza ()
{
    // Não terminado
}

void arcoPreenchido ()
{
    // Cor do circulo
    glColor3f (1.0, 0.0, 1.0);
    // Quantidade de pontos do circulo
    GLfloat qtPontos = 50.0;
    // Angulo de cada ponto do circulo
    GLfloat angulo = 0.0;
    // Tamanho do circulo (raio*2 = diametro)
    GLfloat raio = 100.0;
    // Inicia o bloco do desenho da primitiva
    glBegin (GL_TRIANGLE_FAN);
        for (int i = 0; i < (qtPontos/2); i++)
        {
            // Calculo do angulo relativo ao ponto desejado
            angulo = 2 * PI * i / qtPontos;
            // Cria o vértice
            glVertex2f ((cos(angulo) * raio)+200, (sin(angulo) * raio)+200);
        }
    // Finaliza o bloco do desenho da primitiva
    glEnd ();
}

void referencia ()
{
    glColor3f (1.0,1.0,1.0);
    glLineWidth (1.0);
    glBegin (GL_POLYGON);
        glVertex3f (198.0, 198.0, 0.0); // v1
        glVertex3f (202.0, 198.0, 0.0); // v2
        glVertex3f (202.0, 202.0, 0.0); // v3
        glVertex3f (198.0, 202.0, 0.0); // v4
    glEnd ();
}

