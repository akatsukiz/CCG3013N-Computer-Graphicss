#include <GL/glut.h>

void display1() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gradient background from red to blue
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);  // Red at top
        glVertex2f(-1.0, 1.0);
        glVertex2f(1.0, 1.0);
        glColor3f(0.0, 0.0, 1.0);  // Blue at bottom
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);
    glEnd();
    
    // Primary Colors - Red, Green, Blue
    glBegin(GL_QUADS);
        // Red Square
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.6, 0.6);
        glVertex2f(-0.3, 0.6);
        glVertex2f(-0.3, 0.3);
        glVertex2f(-0.6, 0.3);
        
        // Green Square
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.2, 0.6);
        glVertex2f(0.1, 0.6);
        glVertex2f(0.1, 0.3);
        glVertex2f(-0.2, 0.3);
        
        // Blue Square
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.2, 0.6);
        glVertex2f(0.5, 0.6);
        glVertex2f(0.5, 0.3);
        glVertex2f(0.2, 0.3);
    glEnd();
    
    // Secondary Colors - Cyan, Magenta, Yellow
    glBegin(GL_QUADS);
        // Cyan Square (Green + Blue)
        glColor3f(0.0, 1.0, 1.0);
        glVertex2f(-0.6, 0.0);
        glVertex2f(-0.3, 0.0);
        glVertex2f(-0.3, -0.3);
        glVertex2f(-0.6, -0.3);
        
        // Magenta Square (Red + Blue)
        glColor3f(1.0, 0.0, 1.0);
        glVertex2f(-0.2, 0.0);
        glVertex2f(0.1, 0.0);
        glVertex2f(0.1, -0.3);
        glVertex2f(-0.2, -0.3);
        
        // Yellow Square (Red + Green)
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(0.2, 0.0);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.5, -0.3);
        glVertex2f(0.2, -0.3);
    glEnd();
    
    glutSwapBuffers();
}

void init1() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Remove depth testing as we're doing 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main1(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Removed GLUT_DEPTH
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Task 1 - Primary and Secondary Colors");
    
    init1();
    glutDisplayFunc(display1);
    glutMainLoop();
    return 0;
}