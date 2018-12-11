/*
  Name:        Slide3_Ex3
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 3 do Slide 3 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float xtrans = -2.5, ytrans = -2.5, partialXTrans = xtrans, partialYTrans = ytrans;
int desiredFPS = 15;

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void desenharTabuleiro () {
    
    int i, j = -3.0;
    for (i = -3.0; i < 3.0; i++) {
        for (j = -3.0; j < 3.0; j ++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
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

        glBegin(GL_POLYGON);
          glVertex2f(i, j);
          glVertex2f(i + 1, j);
          glVertex2f(i + 1, j + 1);
          glVertex2f(i, j + 1);
        glEnd();
      }
   }
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); 

    desenharTabuleiro();

    glPushMatrix();
        glColor3f(255.0, 0.0, 0.0);
        glTranslatef(partialXTrans, partialYTrans, 0.0);
        glutSolidSphere(0.48, 20, 20);
    glPopMatrix();

    glutSwapBuffers ();
}

void moverCirculo () {
    if (partialXTrans < xtrans){
      partialXTrans += 0.25;
    }
    else if (partialXTrans > xtrans){
      partialXTrans -= 0.25;
    }

    if (partialYTrans < ytrans){
      partialYTrans += 0.25;
    }
    else if (partialYTrans > ytrans){
      partialYTrans -= 0.25;
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

    moverCirculo();

    tLast = t;

    glutPostRedisplay();

}

float definirPosicao (int pos) {
  if (pos == 0){
    return - 2.5;
  }

  else if (pos == 1) {
    return - 1.5;
  }

  else if (pos == 2){
      return - 0.5;
  }

  else if (pos == 3){
      return 0.5;
  }

  else if (pos == 4){
      return 1.5;
  }

  else {
      return 2.5;
  }
}

void mouse(int button, int state, int x, int y)
{
  if (xtrans == partialXTrans && ytrans == partialYTrans) {
    int posX = x / 80, posY = (480 - y) / 80;
    xtrans = definirPosicao(posX);
    ytrans = definirPosicao(posY);
  }

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (480, 480);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Slide 3 - Exercício 3");
   glutIdleFunc( idle);
   glutMouseFunc( mouse );
   init ();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}