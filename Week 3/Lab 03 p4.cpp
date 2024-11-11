#include <GL/glut.h>
#include <cmath>

// Function to draw the sun (circle with rays)
void drawSun1() {
    const float PI = 3.14159f;
    const int circle_points = 100;
    const float radius = 0.2f;

    // Draw the sun's body (circle)
    glBegin(GL_POLYGON);
    for (int i = 0; i < circle_points; i++) {
        float angle = 2 * PI * i / circle_points;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();

    // Draw the sun's rays
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) { // 12 rays around the circle
        float angle = 2 * PI * i / 12;
        glVertex2f(radius * cos(angle), radius * sin(angle));
        glVertex2f(0.4f * cos(angle), 0.4f * sin(angle)); // Extend the rays outwards
    }
    glEnd();
}

// GLUT display function
void display5() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    drawSun1();
    glFlush();
}

int main5(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Sun Drawing");
    glutInitWindowSize(500, 500);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glutDisplayFunc(display5);
    glutMainLoop();
    return 0;
}
