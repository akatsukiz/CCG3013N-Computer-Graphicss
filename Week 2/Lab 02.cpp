#include <gl/glut.h> //OpenGL toolkit

using namespace std; // There is no need to specific the std prefix for IO stream.

void display(void){ // Render function definition
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); // Clear the window with the background color.
    glFlush(); // Execute OpenGL commands.

}

int main2(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize the GLUT library.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode (single buffer, RGB colors).
    glutInitWindowSize(800, 600); // Set the window size to 800x600.
    glutCreateWindow("Basic OpenGL Structure"); // Create a window with a title.
    glutDisplayFunc(display); // Set the render function.
    glutMainLoop(); // Enter the main loop (keeps the window open).
    return 0;
}
