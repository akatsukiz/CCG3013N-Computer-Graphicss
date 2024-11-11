#include <windows.h> //Load W32 window, console window.
#include <gl/glut.h> //OpenGL toolkit

using namespace std; // There is no need to specific the std prefix for IO stream.

void renderScene(void){ // Render function definition
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // RGBA

	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluOrtho2D(0, 800, 0, 600);
	
	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.
	glFlush(); // Clear all GL executions.
	glFinish(); // Block until all GL executions are completed.
}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single frame buffer with RGB colours.
	glutInitWindowSize(800, 600); // OpenGL window size.
	glutInitWindowPosition(50, 50); // Window position on the screen.
	glutCreateWindow("Hello OpenGL!"); // OpenGL window title.
	glutDisplayFunc(renderScene); // Load render function.
	glutMainLoop(); // Loop frame forever.
	
	system("PAUSE"); // Stop the frame.
	return 0; // Close program.
}

