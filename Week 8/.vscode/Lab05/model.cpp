#include <GL/glut.h>
#include "model.h"

using namespace model;

void Teapot::draw(){
	glColor3f(1.0f, 1.0f, 0.0f);
	glFrontFace(GL_CW);
	//glutSolidSphere(10,30,30);
	glutSolidTeapot(5);
	glFrontFace(GL_CCW);
}

void World::draw(){
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 10.0f);
		teapot.draw();
	glPopMatrix();
}
