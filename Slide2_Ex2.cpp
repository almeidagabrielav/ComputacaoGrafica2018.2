/*
  Name:        Slide2_Ex2
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 2 do Slide 2 da disciplna de Computação Gráfica - 2018.2
*/


#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846

void DesenharEixos(){
  glBegin(GL_LINES);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f( 390.0, 0.0, 0.0);
    glVertex3f(0.0, -10.0, 0.0);
    glVertex3f(0.0,  10.0, 0.0);
  glEnd();
}

void DesenharSeno(int numPartes){
    glClear (GL_COLOR_BUFFER_BIT);
    DesenharEixos();

    int i = 0;
    float variacaoAngulo = 360/numPartes;

    glBegin(GL_LINE_STRIP);
        glColor3f (0.0, 1.0, 0.0);
        for(i = 0; i <= 360; i += variacaoAngulo){
            double grauRad = (i*PI)/180;
            glVertex2f(i, float(sin(grauRad)));
        }       
    glEnd();

    glutSwapBuffers ();
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();
  glutSwapBuffers ();
}

void init (void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0, 390, -2, 2, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity();           
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27:
      exit(0);
    break;
    case 'a':
        DesenharSeno(6);
    break;
    case 'b':
        DesenharSeno(12);
    break;
    case 'c':
        DesenharSeno(180);
    break;
   }
}

int main(int argc, char** argv)
{
    
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (300, 300);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Slide 2 - Exercício 2");
  init ();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  printf("Pressione ESC para fechar.\n");
  printf("Pressione 'a' para abrir o exemplo a).\n");
  printf("Pressione 'b' para abrir o exemplo b).\n");
  printf("Pressione 'c' para abrir o exemplo c).\n");

  glutMainLoop();

  return 0;
}
