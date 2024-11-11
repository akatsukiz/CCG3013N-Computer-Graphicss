#include <GL/glut.h>

void renderScene2(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw black background
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
    glEnd();

	// Set color to Netflix light red
    glColor3f(0.6902f, 0.02352f, 0.05882f);
    
    // Draw right part of the 'N'
    glBegin(GL_POLYGON);
        glVertex2f(0.1f, -0.78f);
        glVertex2f(0.3f, -0.8f);
        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.1f, 0.8f);
    glEnd();
    
    // Draw left part of the 'N'
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, -0.78f);
        glVertex2f(-0.3f, -0.8f);
        glVertex2f(-0.3f, 0.8f);
        glVertex2f(-0.1f, 0.8f);
    glEnd();

	// Set color to Netflix dark red
    glColor3f(0.8980f, 0.03529f, 0.07451f);

	// Draw slash '\' for the middle of N
    glBegin(GL_POLYGON);
        glVertex2f(0.1f, -0.78f);
    	glVertex2f(0.3f, -0.8f);
        glVertex2f(-0.1f, 0.8f);
        glVertex2f(-0.3f, 0.8f);
    glEnd();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Using Colors");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black.
    
    glutDisplayFunc(renderScene2);
    glutMainLoop();
    return 0;
}
