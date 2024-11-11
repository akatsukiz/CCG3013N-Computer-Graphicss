#include <GL/glut.h>
#include <cmath>

// Function to draw the sun (circle with rays)
void drawSun() {
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
        float ray_length = (i % 2 == 0) ? 0.4f : 0.3f; // Alternate between long and short rays
        glVertex2f(radius * cos(angle), radius * sin(angle));
        glVertex2f(ray_length * cos(angle), ray_length * sin(angle));
    }
    glEnd();
}

// GLUT display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    drawSun();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Sun Drawing");
    glutInitWindowSize(500, 500);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
