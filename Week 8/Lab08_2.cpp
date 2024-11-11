#include <GL/glut.h>

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Draw three overlapping squares
    glBegin(GL_QUADS);
        // Red square
        glColor4f(1.0, 0.0, 0.0, 0.5);  // Red with 50% transparency
        glVertex2f(-0.3, 0.3);
        glVertex2f(0.1, 0.3);
        glVertex2f(0.1, -0.1);
        glVertex2f(-0.3, -0.1);
        
        // Blue square
        glColor4f(0.0, 0.0, 1.0, 0.5);  // Blue with 50% transparency
        glVertex2f(-0.1, 0.5);
        glVertex2f(0.3, 0.5);
        glVertex2f(0.3, 0.1);
        glVertex2f(-0.1, 0.1);
        
        // Green square
        glColor4f(0.0, 1.0, 0.0, 0.5);  // Green with 50% transparency
        glVertex2f(0.0, 0.4);
        glVertex2f(0.4, 0.4);
        glVertex2f(0.4, 0.0);
        glVertex2f(0.0, 0.0);
        
        // Black square (for glass effect demonstration)
        glColor4f(0.0, 0.0, 0.0, 0.7);  // Black with 70% transparency
        glVertex2f(0.5, 0.3);
        glVertex2f(0.8, 0.3);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.5, 0.0);
    glEnd();
    
    glDisable(GL_BLEND);
    glutSwapBuffers();
}

void init2() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main2(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Task 2 - Transparency and Glass Effect");
    
    init2();
    glutDisplayFunc(display2);
    glutMainLoop();
    return 0;
}