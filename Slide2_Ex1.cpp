/*
  Name:        Slide2_Ex1
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     12/11/2018
  Description: Exercício 1 do Slide 2 da disciplna de Computação Gráfica - 2018.2
*/

#include <stdio.h>
#include <GL/glut.h>

void DesenharEixos(){
  glBegin(GL_LINES);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f( 10.0, 0.0, 0.0);
    glVertex3f(0.0, -10.0, 0.0);
    glVertex3f(0.0,  10.0, 0.0);
  glEnd();
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();
  glutSwapBuffers ();
}

void DesenharTrianguloA(){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();

  glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f( 0.0f, 0.0f); 
    glVertex2f( 0.75f, 1.3f); 
    glVertex2f( 1.5f, 0.0f); 
  glEnd();

  glutSwapBuffers ();
}

void DesenharTrianguloB(){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();

  glBegin(GL_LINE_LOOP);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f( 0.0f, 0.0f); 
    glVertex2f( 0.75f, 1.3f); 
    glVertex2f( 1.5f, 0.0f); 
  glEnd();

  glutSwapBuffers ();
}

void DesenharTriangulosC(void){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();

  glColor3f (1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
    glVertex2f( 0.0f, 0.0f); 
    glVertex2f( 0.75f, 1.3f); 
    glVertex2f( 1.5f, 0.0f); 
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f( 0.0f, 0.0f); 
    glVertex2f( -0.75f, -1.3f); 
    glVertex2f( -1.5f, 0.0f); 
  glEnd();

  glutSwapBuffers ();

}

void DesenharLinhasD(){
  glClear (GL_COLOR_BUFFER_BIT);
  DesenharEixos();

  glBegin(GL_LINE_STRIP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f( -0.7f, 1.1f);
    glVertex2f( -1.3f, 0.0f); 
    glVertex2f( -0.7f, -1.1f);
    glVertex2f( 0.7f, -1.1f);
    glVertex2f( 1.3f, 0.0f);
    glVertex2f( 0.7f, 1.1f);
  glEnd();

  glutSwapBuffers ();
}

void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.7, 1.7, -1.7, 1.7, -1.7, 1.7);

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
      DesenharTrianguloA();
    break;
    case 'b':
      DesenharTrianguloB();
    break;
    case 'c':
      DesenharTriangulosC();
    break;
    case 'd':
      DesenharLinhasD();
    break;
   }
}

int main(int argc, char** argv)
{
    
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (300, 300);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Slide 2 - Exercício 1");
  init ();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

	printf("Pressione ESC para fechar.\n");
  printf("Pressione 'a' para abrir o exemplo a).\n");
  printf("Pressione 'b' para abrir o exemplo b).\n");
  printf("Pressione 'c' para abrir o exemplo c).\n");
  printf("Pressione 'd' para abrir o exemplo d).\n");

  glutMainLoop();

  return 0;
}
