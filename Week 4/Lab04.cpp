#include <iostream>
#include <windows.h> //Load W32 window, console window.
#include <gl/glut.h> //OpenGL toolkit
#include <math.h>
#include "object.h"

#define PI 3.14159265

using namespace std; // There is no need to specific the std prefix for IO stream.

GLfloat angle = 45;
Object sprite01 = Object(0, 0);
Object sprite02 = Object();
Object sprite03 = Object();
Object sprite04 = Object();
Object sprite05 = Object(400, 300);

void renderScene(void){ // Render function definition
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // RGBA, white background

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600); // Space 2D canvas space.
	
	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.

	glColor3f(1.0f, 0.0f, 0.0f); // Red brush
	
	if(!sprite01.once){
		// sprite01.translate(400, 300);
		sprite01.rotate((GLfloat)sprite01.x, (GLfloat)sprite01.y, (GLfloat)(500), angle);
		sprite01.size = 1;
		sprite01.scale(20);
		sprite01.once = true;
	}	
	sprite01.drawPoint(sprite01.size);
	
	glColor3f(0.0f, 1.0f, 0.0f); // Green brush
	sprite02.drawLine(0, 0, 300, 300);
	
	glColor3f(0.0f, 0.0f, 1.0f); // Blue brush
	sprite03.drawTriangle(0, 0, 0, 100, 100, 100);
	
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan brush
	sprite04.drawRect(500, 25, 100, 100);
	
	// glColor3f(1.0f, 0.0f, 1.0f); // Magenta brush
	// sprite05.drawRegularPolygon(50, 8, 0);
	
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
