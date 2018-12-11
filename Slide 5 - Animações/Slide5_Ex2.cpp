/*
  Name:        Slide5_Ex2
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     20/11/2018
  Description: Exercício 2 do Slide 5 da disciplna de Computação Gráfica - 2018.2
*/


#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "extras.h"
#include <math.h>

// Globals
int width  = 1000, height = 500,  maxHeight = 600;
float rotationX = 0.0, rotationY = 0.0, jumpX = 10, jumpY = -2;
float last_x = 20, last_y = 400, desiredFPS = 15, last_y_Aux = 20;


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

  //atualizando posicao da esfera
  if (last_x >= 980 || last_x < 20){
      jumpX *= -1;
   }

   last_x += jumpX;

   if (jumpY < 0) {
      if (last_y_Aux > 4) {
         last_y_Aux += jumpY;
         last_y = pow(last_y_Aux, 2);
      } else {
         jumpY *= -1;
         maxHeight *= 0.75;
      }
   } 
   else if (jumpY > 0) {
      last_y_Aux += jumpY;
      float aux = pow(last_y_Aux, 2);
      if (aux <= maxHeight) {
         last_y = aux;
      } else {
         jumpY *= -1;
      }
   } 
   tLast = t;
   glutPostRedisplay();
}

void init(void)
{
  float sphereSize = 30.0;
  glClearColor (0.5, 0.5, 0.5, 0.0);
  glShadeModel (GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);              
	initLight(width, height);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho(0.0, width, 0.0, height, -sphereSize, sphereSize);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity ();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   setMaterial();

   glPushMatrix();
      glTranslatef(last_x, last_y, 0.0); 
      glutSolidSphere(20.0, 100, 100);
    glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   width = w;
   height = h;
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

void specialKeysPress(int key, int x, int y)
{
   printf("%d\n", key);
   switch(key)
   {
      case GLUT_KEY_RIGHT:
         if (jumpX != 0) {
          jumpX += 1;
         }
      break;
      case GLUT_KEY_LEFT:
         if (jumpX != 0) {
           if(jumpX - 1 < 1){
             jumpX = 1;
           }
           else{
             jumpX -= 1;
           }
         }
        break;
      default:
         break;
   break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (width, height);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Slide 5 - Exercício 2");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(specialKeysPress);
   glutIdleFunc(idle);
   glutMainLoop();
   return 0;
}
