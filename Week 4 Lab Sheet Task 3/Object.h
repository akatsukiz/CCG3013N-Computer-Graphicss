#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>
#include "math.h"
#include <GL/glut.h>
#define PI 3.14159265

using namespace std;

class Object{
public:
    Object();
    Object(GLfloat x, GLfloat y);
    
    void drawPoint(GLfloat size);
    void drawLine(GLint x1, GLint y1, GLint x2, GLint y2);
    void drawTriangle(GLint x1, GLint y1,
                  GLint x2, GLint y2,
                  GLint x3, GLint y3);
    void drawRect(GLint x, GLint y, GLint sizeX, GLint sizeY);
    void drawRegularPolygon(GLint radius, GLint side,
                            GLfloat orientation);
    void drawCircle(GLint centerX, GLint centerY, GLint radius); // New function
    
    // 2D transformation
    void translate(GLint tx, GLint ty);
    void rotate(GLfloat centerX, GLfloat centerY,
                GLfloat radius, GLfloat& angle);
    void scale(GLfloat factor);    
    GLfloat x, y, size;
    GLboolean once;
};
#endif