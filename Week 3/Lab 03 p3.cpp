#include <GL/glut.h>

// Function to set the viewport and projection
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Maintain aspect ratio
    glMatrixMode(GL_MODELVIEW);
}

// Function to draw a rectangle with the correct aspect ratio
void display4() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Drawing a rectangle
    glBegin(GL_QUADS);
    glVertex2f(-0.75f, -0.5f);
    glVertex2f(0.75f, -0.5f);
    glVertex2f(0.75f, 0.5f);
    glVertex2f(-0.75f, 0.5f);
    glEnd();

    glFlush();
}

int main4(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600); // 4:3 aspect ratio
    glutCreateWindow("Aspect Ratio Example");
    glutDisplayFunc(display4);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
