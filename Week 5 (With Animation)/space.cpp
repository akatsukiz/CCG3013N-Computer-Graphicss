#include <windows.h>
#include <GL/glut.h>
#include "space.h"
#include <cmath> // for sin, cos functions
#include "model.h"

using model::World;

World world;

using namespace std;

ViewFrustum viewer;
Window window;

float distanceChange = 0.0; // angle to control smooth transitions
float M_PI = 3.142;

void windowSettings(){
	window.title = "3D Graphics";
	window.offsetX = 50;
	window.offsetY = 50;
	window.width = 800;
	window.height = 600;
}

void spaceSettings(){
	viewer.eyeX = 0.0;
	viewer.eyeY = 20.0;
	viewer.eyeZ = 40.0;
	viewer.refX = 7.0;
	viewer.refY = 7.0;
	viewer.refZ = 7.0;
	viewer.upX = 0.0;
	viewer.upY = 1.0;
	viewer.upZ = 0.0;
	viewer.nearZ = 0.1;
	viewer.farZ = 500.0;
	viewer.fieldOfView = 100.0;
	viewer.aspectRatio = static_cast<GLdouble> (window.width / window.height);
}

void init(){
	windowSettings();
	spaceSettings();
}

void perspectiveView(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewer.fieldOfView,
				   viewer.aspectRatio,
				   viewer.nearZ,
				   viewer.farZ);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(viewer.eyeX, viewer.eyeY, viewer.eyeZ,
			   viewer.refX, viewer.refY, viewer.refZ,
			   viewer.upX, viewer.upY, viewer.upZ);
}

// Animate the camera's position smoothly
void animateCamera() {
    // Increment the angle for smooth transition
    distanceChange += 0.1;
    if (distanceChange > 2 * 100) {
        distanceChange = 0.0; // Reset angle after a full cycle
    }

    // Update the camera position in a circular path around the origin (0,0,0)
    viewer.eyeX = distanceChange; 
    viewer.eyeY = 0;
    viewer.eyeZ = 0;
    
    // Optionally, you can also make the look-at point or up vector change over time
    //viewer.refX = 5 * sin(angle / 2); // Change the look-at point smoothly
    //viewer.refY = 5 * cos(angle / 2);
    
    perspectiveView();  // Update the perspective with new camera settings
    glutPostRedisplay(); // Redraw the scene with updated camera position
}

void renderer(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	
	// 3D models to be rendered.
	world.draw();
	
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
	glFinish();
}

void lighting(){
	static GLfloat diffuse[] = {0.0f, 0.0f, 0.0f, 1.0f};
	static GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	static GLfloat ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
	static GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.0f};
	static GLfloat position[] = {10.0f, 10.0f, 10.0f, 1.0f};
	short shininess = 128;
	
	glDisable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glEnable(GL_LIGHT0);
	
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	
	glEnable(GL_COLOR_MATERIAL);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	
	glEnable(GL_NORMALIZE);
}

int main(){
	init();
	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(window.offsetX, window.offsetY);
	glutInitWindowSize(window.width, window.height);
	glutCreateWindow(window.title.c_str());
	
	glutDisplayFunc(renderer);
	
	glutIdleFunc(animateCamera); // Set the idle function to animate the camera

	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_CULL_FACE);
	
	perspectiveView();
	
	lighting();
	
	glutMainLoop();
	
	system("PAUSE");
	return 0;
}
