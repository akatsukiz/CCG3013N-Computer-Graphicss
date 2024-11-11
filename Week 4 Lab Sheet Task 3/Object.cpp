#include "object.h"

// Default constructor
Object::Object(){
	once = false;
}

// Constructor with x and y
Object::Object(GLfloat x, GLfloat y){
	this->x = x;
	this->y = y;
	once = false;
}

void Object::drawPoint(GLfloat size){
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2i(this->x, this->y);
	glEnd();
	glPopMatrix();
}

void Object::drawLine(GLint x1, GLint y1, GLint x2, GLint y2){
	glPushMatrix();
	this->x = x1;
	this->y = y1;
	glBegin(GL_LINES);
		glVertex2i(this->x, this->y);
		glVertex2i(x2, y2);
	glEnd();
	glPopMatrix();
}

void Object::drawCircle(GLint centerX, GLint centerY, GLint radius) {
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center point
    for (int i = 0; i <= 360; i++) {
        float angle = i * PI / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void Object::drawTriangle(GLint x1, GLint y1,
						  GLint x2, GLint y2,
						  GLint x3, GLint y3){
	glPushMatrix();
	glBegin(GL_TRIANGLES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
	glEnd();
	glPopMatrix();
}

void Object::drawRect(GLint x, GLint y, GLint sizeX, GLint sizeY){
	for(this->x = x; this->x < x+sizeX; this->x++){
		// glColor3f((this->x - x)*1.0f/sizeX, 0.0f, 0.0f); // Left = black, right = red.
		glColor3f(1.0f - ((this->x - x)*1.0f/sizeX), 0.0f, 0.0f); // Left = red, right = black.
		for(this->y = y; this->y < y+sizeY; this->y++){
			// glColor3f(1.0f - ((this->y - y)*1.0f/sizeY), 0.0f, 0.0f); // top = black, bottom = red.
			// glColor3f((this->y - y)*1.0f/sizeY, 0.0f, 0.0f); // top = red, bottom = black.
			drawPoint(1);
		}
	}
}

void Object::drawRegularPolygon(GLint radius, GLint side,
								GLfloat orientation){
	if(side >= 3){
		glPushMatrix();
		GLint xp, yp;
		glBegin(GL_POLYGON);
			for(int i=0; i<side; i++){
				xp = (int)(this->x + radius * cos(orientation + 2*PI/side*i));
				yp = (int)(this->y + radius * sin(orientation + 2*PI/side*i));
				glVertex2i(xp, yp);
			}
		glEnd();
		glPopMatrix();		
	}
	else{
		cerr<<"Can't render polygon with less than 3 sides."<<endl;
	}
}

void Object::translate(GLint tx, GLint ty){
	this->x = this->x + tx;
	this->y = this->y + ty;
}

void Object::rotate(GLfloat centerX, GLfloat centerY,
			GLfloat radius, GLfloat& angle){
	this->x = centerX + radius * cos(angle * PI / 180);
	this->y = centerY + radius * sin(angle * PI / 180);
	if(angle < 360){
		angle++;
	}
	else{
		angle = 0.0;
	}
}
			
void Object::scale(GLfloat factor){
	this->size = this->size * factor;
}
