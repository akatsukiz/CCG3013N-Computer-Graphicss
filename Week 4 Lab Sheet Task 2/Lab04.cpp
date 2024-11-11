#include <iostream>

#include <windows.h> //Load W32 window, console window.

#include <gl/glut.h> //OpenGL toolkit

#include <math.h>

#include "object.h"
 
#define PI 3.14159265
 
using namespace std; // There is no need to specific the std prefix for IO stream.
 
Object sprite04 = Object();

GLfloat angle = 45;
 
void renderScene(void){ // Render function definition

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // RGBA, white background
 
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//gluOrtho2D(0, 800, 0, 600); // (0,0) is in bottom left

	gluOrtho2D(-400, 400, -300, 300); // (0,0) is in the center

	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.
 
 
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan brush

	for(int i=0; i<24; i++){

			glPushMatrix();

		    glRotatef(i*15.0f, 0.0f, 0.0f, 1.0f);

		    sprite04.drawRect(0, 0, 50, 50);

			glPopMatrix();

	}

	glFlush(); // Clear all GL executions.

	glFinish(); // Block until all GL executions are completed.

}
 
int main(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single frame buffer with RGB colours.

	glutInitWindowSize(800, 600); // OpenGL window size.

	glutInitWindowPosition(50, 50); // Window position on the screen.

	glutCreateWindow("Canvas drawing"); // OpenGL window title.

	glutDisplayFunc(renderScene); // Load render function.

	glutMainLoop(); // Loop frame forever.

	system("PAUSE"); // Stop the frame.

	return 0; // Close program.

}
 