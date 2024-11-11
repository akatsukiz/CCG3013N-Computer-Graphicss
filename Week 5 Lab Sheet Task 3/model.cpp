#include <GL/glut.h>
#include "model.h"

using namespace model;

void Teapot::draw(){
    glColor3f(1.0f, 1.0f, 0.0f);
    glFrontFace(GL_CW);
    glutSolidTeapot(5);
    glFrontFace(GL_CCW);
}

void World::draw(){
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 10.0f);
        glRotatef(45.0f, 0.0f, 1.0f, 0.0f);  // Rotate 45 degrees around y-axis
        teapot.draw();
    glPopMatrix();
}