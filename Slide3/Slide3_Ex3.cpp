/*
  Name:        Slide3_Ex1
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 2 do Slide 3 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float xtrans = 0, ytrans = 0, partialXTrans = 0, partialYTrans = 0;
float desiredFPS = 10;

void desenharTabuleiro()
{
    int i = -3, j = 3;
    for (i = -3; i < 3; i++) {
        for (j = -3; j < 3; j++) {
            if (i % 3 == 0) {
                if (j % 3 == 0){
                    glColor3f (255.0, 255.0, 255.0);
                }
                else {
                    glColor3f (0.0, 0.0, 0.0);
                }
            } 
            else {
                if (j % 2 == 0) {
                    glColor3f (0.0, 0.0, 0.0);
                }
                else {
                    glColor3f (255.0, 255.0, 255.0);
                }
            }
        }

        glBegin(GL_POLYGON);
          glVertex3f(i, j, 0);
          glVertex3f(i+1, j, 0);
          glVertex3f(i+1, j+1, 0);
          glVertex3f(i, j+1, 0);
        glEnd();
    }
}


void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   desenharTabuleiro();

   glPushMatrix();
      glTranslatef(partialXTrans, partialYTrans, 0.0);
   glPopMatrix();

   glutSwapBuffers ();
   glutPostRedisplay();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void atualizarPosicaoCirculo(){

    if (partialXTrans < xtrans){
      partialXTrans += 1;
    }
    else if (partialXTrans > xtrans){
      partialXTrans -= 1;
    }

    if (partialYTrans < ytrans){
      partialYTrans += 1;
    }
    else if (partialYTrans > ytrans){
      partialYTrans -= 1;
    }
}

void idle()
{
    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;

    t = glutGet(GLUT_ELAPSED_TIME);
    t /= 1000.0;

    frameTime = t - tLast;
    desiredFrameTime = 1.0 / (float) (desiredFPS);

    if( frameTime <= desiredFrameTime)
        return;

    atualizarPosicaoCirculo();

    tLast = t;

    glutPostRedisplay();

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (525, 525);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Slide 3 - Exercício 3");
   glutIdleFunc(idle);
   init ();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}