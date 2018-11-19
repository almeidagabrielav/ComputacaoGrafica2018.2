/*
  Name:        Slide2_Ex3
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 3 do Slide 2 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(void)
{
   glClearColor(0.0,0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);
}

void DesenharEixos()
{
    glBegin(GL_LINES);
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(0.0, -10.0, 0.0);
        glVertex3f(0.0,  10.0, 0.0);
        glColor3f (  0.0,   1.0, 0.0);
        glVertex3f(-1000.0, 0.0, 0.0);
        glVertex3f( 100.0, 0.0, 0.0);
    glEnd();
}

void DesenharObjetosVPSupEsq()
{ 
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f(2.0, 2.0, 0.0);
      glVertex3f(8.9, 2.0, 0.0);
      glVertex3f(2.0, 8.9, 0.0);
   glEnd();

   glColor3f(0.5f, 1.0f, 1.0f);
   glBegin(GL_LINE_LOOP);
      glVertex3f(2.0, -2.0, 0.0);
      glVertex3f(8.9, -2.0, 0.0);
      glVertex3f(2.0, -8.9, 0.0);
   glEnd();

   glColor3f(2.0f, 0.5f, 1.0f);
   glBegin(GL_LINE_STRIP);
      glVertex3f(-2.0, -2.0, 0.0);
      glVertex3f(-9.0, -2.0, 0.0);
      glVertex3f(-2.0, -8.9, 0.0);
      glVertex3f(-9.0, -8.9, 0.0);
   glEnd();
}

void DesenharObjetosVPSupDir()
{ 
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f(8.9, 2.0, 0.0);
      glVertex3f(37.0, 2.0, 0.0);
      glVertex3f(8.9, 8.9, 0.0);
   glEnd();
}

void DesenharObjetosVPInfDir()
{ 
   glColor3f(0.5f, 1.0f, 1.0f);
   glBegin(GL_LINE_LOOP);
      glVertex3f(8.9, -2.0, 0.0);
      glVertex3f(37.0, -2.0, 0.0);
      glVertex3f(8.9, -8.9, 0.0);
   glEnd();
}

void DesenharObjetosVPInfEsq()
{ 
   glColor3f(2.0f, 0.5f, 1.0f);
   glBegin(GL_LINE_STRIP);
      glVertex3f(-200.0, -2.0, 0.0);
      glVertex3f(-900.0, -2.0, 0.0);
      glVertex3f(-200.0, -8.9, 0.0);
      glVertex3f(-900.0, -8.9, 0.0);
   glEnd();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Define viewport do canto inferior esquerdo
    glViewport ((int) 10, (int) 10, (int) 190, (int) 190);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-1000.0, 120, -10, 1, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DesenharEixos();
    DesenharObjetosVPInfEsq();

    // Define viewport do canto superior esquerdo 
    glViewport ((int) 10, (int) 200, (int) 190, (int) 190);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DesenharEixos();
    DesenharObjetosVPSupEsq();

    // Define viewport do canto inferior direito
    glViewport ((int) 200, (int) 10, (int) 190, (int) 190);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-5.0, 40, -10, 1, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DesenharEixos();
    DesenharObjetosVPInfDir();

    // Define viewport do canto superior direito 
    glViewport ((int) 200, (int) 200, (int) 190, (int) 190);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-5.0, 40.0, -1.0, 10.0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DesenharEixos();
    DesenharObjetosVPSupDir();

    glutSwapBuffers();
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27 :
         exit(0);
      break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize (400,400);
   glutInitWindowPosition (20,20);
   glutCreateWindow ("Slide 2 - Exercício 3");
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}


