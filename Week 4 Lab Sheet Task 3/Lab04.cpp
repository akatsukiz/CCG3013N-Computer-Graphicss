#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include "object.h"

#define PI 3.14159265

using namespace std;

Object sprite04 = Object();
GLfloat angle = 45;

void renderScene(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the original pattern
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan brush
    for(int i=0; i<24; i++){
        glPushMatrix();
        glRotatef(i*15.0f, 0.0f, 0.0f, 1.0f);
        sprite04.drawRect(0, 0, 50, 50);
        glPopMatrix();
    }

    // Draw a circle
    glColor3f(1.0f, 0.0f, 0.0f); // Red brush
    sprite04.drawCircle(0, 0, 100); // Draw a circle at the center with radius 100

    glFlush();
    glFinish();
}

int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Canvas drawing with Circle");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    system("PAUSE");
    return 0;
}