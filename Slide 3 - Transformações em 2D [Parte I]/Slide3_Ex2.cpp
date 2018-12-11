/*
  Name:        Slide3_Ex2
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 2 do Slide 3 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;
float desiredFPS = 10;
float partialAngle = 0, partialScale = 1.0, partialXTrans = 0, partialYTrans = 0;

void showMenu()
{
   int op;
   system("cls");
   printf("\n=== MENU ===");
   printf("\n1 - Translacao");
   printf("\n2 - Rotacao");
   printf("\n3 - Escala");
   printf("\n4 - Sair");
   printf("\nOpcao: ");

   scanf("%d", &op);
   switch(op)
   {
      case 1:
         printf("\n\nInforme o vetor de translacao (entre -100.0 e 100.0)");
         printf("\nX : ");
         scanf("%f", &xtrans);
         printf("Y : ");
         scanf("%f", &ytrans);
      break;
      case 2:
         printf("\n\nInforme o angulo de rotacao (em graus): ");
         scanf("%f", &angle);
      break;
      case 3:
         printf("\n\nInforme o fator de escala: ");
         scanf("%f", &scale);
      break;
      case 4:
         exit(1);
      break;
      default:
         printf("\n\nOpcao invalida\n\n");
      break;
   }
}

void desenharEixos()
{
   glColor3f (0.0, 1.0, 0.0);
   glBegin(GL_LINES);
      glVertex2f (0.0, -100.0);
      glVertex2f (0.0, 100.0);
      glVertex2f (-100.0, 0.0);
      glVertex2f (100.0, 0.0);
   glEnd();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   desenharEixos();

   glColor3f (1.0, 0.0, 0.0);

   glPushMatrix();
      glTranslatef(partialXTrans, partialYTrans, 0.0);
      glRotatef(partialAngle, 0.0, 0.0, 1.0);
      glScalef(partialScale, partialScale, partialScale);
      glutWireCube(10);
   glPopMatrix();

   glutSwapBuffers ();
   glutPostRedisplay();

   if(partialAngle == angle && partialScale == scale 
      && partialXTrans == xtrans && partialYTrans == ytrans)
    {
        showMenu();
    }
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void atualizarPosicaoQuadrado(){

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

    if (partialAngle < angle){
      partialAngle += 1;
    }
    else if (partialAngle > angle){
      partialAngle -= 1;
    }

    if (partialScale < scale){
      partialScale += 0.25;
    }
    else if (partialScale > scale){
      partialScale -= 0.25;
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

    atualizarPosicaoQuadrado();

    tLast = t;

    glutPostRedisplay();

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Slide 3 - Exercício 2");
   glutIdleFunc(idle);
   init ();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}