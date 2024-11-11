#include <GL/glut.h>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "line.h"
#include "polygon.h"

// Define constants
const int windowWidth = 800;
const int windowHeight = 600;
const float rotationAngle = 45.0f; // Rotation in degrees

Rectangle* rect;

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the buffer

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2);

    // Switch to model view matrix for transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	for(int i=0;i<12; i++){
    	glColor3f(i/12.0f, 0.0f, 0.0f); // Red color
		rect->rotate(i*15); // Rotate the rectangle by 15 degrees
    	rect->draw();                // Draw the rectangle
	
    }
    

    glFlush(); // Ensure everything is rendered
}

int main(int argc, char** argv) {
    // Initialize the rectangle object with width 50 and height 50 at position (0, 0)
    rect = new Rectangle(0.0f, 0.0f, 100.0f, 100.0f);

    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Rectangle");

    // Set background color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();

    // Cleanup
    delete rect;
    return 0;
}

