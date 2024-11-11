#include <GL/glut.h>
 
void drawSquare3() {
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
}
 
void display3() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Start at 0 degrees, continue until we reach (or exceed) 360 degrees
    for(float angle = 0; angle < 360.0f; angle += 15.0f) {
        glPushMatrix();
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        // Calculate color based on angle
        glColor3f(angle/360.0f, 0.5f, 1.0f - angle/360.0f);
        drawSquare3();
        glPopMatrix();
    }
 
    glFlush();
}
 
int main3(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rotating Squares - 360 degrees");
    glutDisplayFunc(display3);
    glutMainLoop();
    return 0;
}