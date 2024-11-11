#ifndef _OJBECT_H_
#define _OBJECT_H_
#include <iostream>
#include "math.h"
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433
#endif

using namespace std;

class Object
{
public:
	Object();
	Object(GLfloat x, GLfloat y);
	~Object();

	// 2D primitives
	void drawPoint(GLfloat x, GLfloat y, GLfloat size);
	void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness);
	void drawTriangle(GLfloat x1, GLfloat y1,
					  GLfloat x2, GLfloat y2,
					  GLfloat x3, GLfloat y3);
	void drawQuad(GLfloat x1, GLfloat y1,
				  GLfloat x2, GLfloat y2,
				  GLfloat x3, GLfloat y3,
				  GLfloat x4, GLfloat y4);
	void drawRect(GLfloat width, GLfloat height);
	void drawRegularPolygon(GLfloat cx, GLfloat cy, GLfloat radius, GLint side, GLfloat orientation, GLfloat width, GLfloat height);

	// 2D Circle & Torus
	void drawCircle(GLfloat radius, GLfloat startDegree, GLfloat endDegree);
	void drawTorus(GLfloat radius, GLfloat thickness, GLfloat startDegree, GLfloat endDegree);

	// Rounded rectangle
	void drawRoundedRectFill(GLfloat width, GLfloat height, GLfloat radius);
	void drawRoundedRectLine(GLfloat width, GLfloat height, GLfloat radius, GLfloat thickness);

	// Heart shape
	void drawHeart(GLfloat size);

	// Battery shape
	void drawBattery(GLfloat size, GLfloat thickness, GLfloat radius, GLfloat power);

	// Taut Belt
	void drawTautBelt(GLfloat circleRadius1, GLfloat circleRadius2, GLfloat h, GLfloat orientation);

	// 2D transformation
	void translate(GLfloat tX, GLfloat tY);
	void rotate(GLfloat t, GLfloat pX, GLfloat pY);
	void mirrorX();
	void mirrorY();
	void scale(GLfloat sX, GLfloat sY);
	void scale(GLfloat scale);

	// Utilities
	void drawText(char *string, GLfloat size);

	void static glEndReset();

	// Private members
	GLfloat x, y;
};

#endif