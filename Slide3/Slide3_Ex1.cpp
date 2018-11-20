/*
  Name:        Slide3_Ex1
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 1 do Slide 3 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;

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
      glTranslatef(xtrans, ytrans, 0.0);
      glRotatef(angle, 0.0, 0.0, 1.0);
      glScalef(scale, scale, scale);
      glutWireCube(10);
   glPopMatrix();

   glutSwapBuffers ();
   glutPostRedisplay();

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

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27:
         exit(0);
      break;
      case '+':
         scale += 1.0;
      break;
      case '-':
         if(scale != 1.0){
            scale -= 1.0;
         }
      break;
      case 'r':
         angle += 1;
      break;
      case 'R':
         angle -= 1;
      break;
   }
}

void specialKeysPress(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			ytrans += 1;
		break;
		case GLUT_KEY_DOWN:
			ytrans -= 1;
		break;
		case GLUT_KEY_RIGHT:
			xtrans += 1;
		break;
		case GLUT_KEY_LEFT:
			xtrans -= 1;
	break;
		default:
			printf("\nPressionou outra tecla especial não mapeada!");
	break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Slide 3 - Exercício 1");
   init ();
   glutSpecialFunc( specialKeysPress );
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}