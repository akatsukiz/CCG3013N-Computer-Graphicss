#include <GL/glut.h>

// Function to draw 2D primitive shapes
void drawPrimitiveShapes() {
    // Draw a point
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.1f);
    glEnd();

    // Draw a line
    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(0.8f, -0.9f);
    glVertex2f(0.0f, 0.2f);
    glEnd();
}

// GLUT display function
void display1() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPrimitiveShapes();
    glFlush();
}

int main1(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("2D Primitive Shapes");
    glutDisplayFunc(display1);
    glutMainLoop();
    return 0;
}
