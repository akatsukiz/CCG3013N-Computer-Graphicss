#include <GL/glut.h>

// Function to draw a square
void drawSquare2() {
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

// GLUT display function
void display2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Translation
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    drawSquare2();
    glPopMatrix();

    // Rotation
    glPushMatrix();
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    drawSquare2();
    glPopMatrix();

    // Scaling
    glPushMatrix();
    glScalef(0.5f, 2.0f, 1.0f);
    drawSquare2();
    glPopMatrix();

    glFlush();
}

int main2(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("2D Transformations");
    glutDisplayFunc(display2);
    glutMainLoop();
    return 0;
}
