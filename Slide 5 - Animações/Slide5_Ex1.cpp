/*
  Name:        Slide5_Ex1
  Copyright:   Version 1
  Authors:     Gabriela Almeida e Gabriel Antonio
  Release:     19/11/2018
  Description: Exercício 1 do Slide 5 da disciplna de Computação Gráfica - 2018.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

float desiredFPS = 3;

bool fullScreen = false;

float greenTriangleX = 0.3, greenTriangleY = 0.5,
    greenTriangleXDirection = 0.1, greenTriangleYDirection = 0.1;

const float greenTriangleXAux = 0.7, greenTriangleYAux = 0.5,
    greenTriangleXAux2 = 0.2, greenTriangleYAux2 = 0.2;

float redTriangleX = 0.2, redTriangleY = 0.2,
    redTriangleXDirection = 0.1, redTriangleYDirection = 0.1;

const float redTriangleXAux = 0.8, redTriangleYAux = 0.8,
    redTriangleXAux2 = 0.4, redTriangleYAux2 = 0.5;

void atualizarTriangulos(){
    if(greenTriangleXAux + greenTriangleX >= 1 || greenTriangleXAux2 + greenTriangleX <= 0.1) {
        greenTriangleXDirection *= -1;
    }

    if(greenTriangleYAux + greenTriangleY >= 1 || greenTriangleYAux2 + greenTriangleY <= 0.1) {
        greenTriangleYDirection *= -1;
    }

    greenTriangleX += greenTriangleXDirection;
    greenTriangleY += greenTriangleYDirection;

    if(redTriangleXAux + redTriangleX >= 1 || 
       redTriangleXAux2 + redTriangleX <= 0) {
            redTriangleXDirection *= -1;
    }

    if(redTriangleYAux + redTriangleY >= 1 || redTriangleYAux2 + redTriangleY <= 0) 
        redTriangleYDirection *= -1;
        
    redTriangleX += redTriangleXDirection;
    redTriangleY += redTriangleYDirection;
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

    atualizarTriangulos();
    tLast = t;

    glutPostRedisplay();

}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
    glColor3f (0.0, 1.0, 0.0);

    glPushMatrix();
        glTranslatef(greenTriangleX, greenTriangleY, 0);
        glBegin(GL_TRIANGLES);
            glVertex2f (0.3, greenTriangleYAux2);
            glVertex2f (greenTriangleXAux, 0.2);
            glVertex2f (greenTriangleXAux2, greenTriangleYAux);
        glEnd();
    glPopMatrix();

    glColor3f (1.0, 0.0, 0.0);

    glPushMatrix();
        glTranslatef(redTriangleX, redTriangleY, 0);
        glBegin(GL_TRIANGLES);
            glVertex2f (0.4, redTriangleYAux);
            glVertex2f (redTriangleXAux, redTriangleYAux2);
            glVertex2f (redTriangleXAux2, 0.4);
        glEnd();
    glPopMatrix();
    
    glutSwapBuffers ();
}

void init (void)
{
    printf("Comandos:\n");
    printf("1 - Pressione a tecla 1 para entrar no modo tela cheia.\n");
    printf("2 - Pressione a tecla 2 para sair do modo tela cheia.\n");
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key)
   {
    case '1':
        glutFullScreen();
        fullScreen = true;
    break;

    case '2':
        glutReshapeWindow(600, 600);
        glutPositionWindow(30,30);
        fullScreen = false;
    break;

    case 27:
      exit(0);
      break;
    default:
      break;
   }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (30, 30);
    glutCreateWindow ("Slide 5 - Exercício 1");
    glutKeyboardFunc(keyboard);
    glutIdleFunc( idle);
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}