#include <GL/glut.h>

// Variables to control the group position (for translation)
float groupX = 0.0f, groupY = 0.0f, groupZ = 0.0f;
// Variables to control the rotation
float rotX = 0.0f, rotY = 0.0f; // Rotation around X and Y axes

void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void drawSphere() {
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);  // Red color for the sphere
    glutSolidSphere(0.5, 30, 30); // Radius, Slices, Stacks
    glPopMatrix();
}

void drawCube() {
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); // Blue color for the cube
    glutSolidCube(1.0);       // Side length of the cube
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix(); // Start transformation for the group of objects
        glTranslatef(groupX, groupY, groupZ);
        glRotatef(rotX, 1.0f, 0.0f, 0.0f); // Rotate around X axis
        glRotatef(rotY, 0.0f, 1.0f, 0.0f); // Rotate around Y axis

        // Draw the sphere and cube at different positions
        glPushMatrix();
        glTranslatef(-1.0f, 0.0f, 0.0f); // Move the sphere to the left
        drawSphere();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.0f, 0.0f, 0.0f); // Move the cube to the right
        glRotatef(45,1.0f,1.0f,0.0f);
		drawCube();
        glPopMatrix();

    glPopMatrix(); // End transformation for the group

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Set viewport to window dimensions
    glMatrixMode(GL_PROJECTION);              // Switch to projection matrix
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0); // Perspective projection
    glMatrixMode(GL_MODELVIEW);               // Switch back to modelview matrix
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,   // Eye position (camera is 5 units away)
              0.0, 0.0, 0.0,   // Center of the scene (look at origin)
              0.0, 1.0, 0.0);  // Up direction
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            groupY += 0.1f; // Move up
            break;
        case 's':
            groupY -= 0.1f; // Move down
            break;
        case 'a':
            groupX -= 0.1f; // Move left
            break;
        case 'd':
        	groupX += 0.1f; //Move right
        case 'q':
        	groupZ -= 0.1f; // Move backward (along Z-axis)
        	break;
        case 'e':
        	groupZ += 0.1f; // Move forward (along Z-axis)
        	break;
    }
    glutPostRedisplay(); // Redraw the scene with the new positions
}

void keyboard2(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            groupY += 0.1f; // Move up
            break;
        case GLUT_KEY_DOWN:
            groupY -= 0.1f; // Move down
            break;
        case GLUT_KEY_LEFT:
            groupX -= 0.1f; // Move left
            break;
        case GLUT_KEY_RIGHT:
            groupX += 0.1f; // Move right
            break;
    }
    glutPostRedisplay(); // Redraw the scene with the new positions
}


int mouseX, mouseY;
bool isDragging = false;
bool isRotating = false;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseX = x;
        mouseY = y;
        isDragging = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        isDragging = false;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        mouseX = x;
        mouseY = y;
        isRotating = true; // Enable rotation for right-click
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        isRotating = false;
    }
}

void motion(int x, int y) {
    if (isDragging) {
        groupX += (x - mouseX) * 0.01f; // Change X based on mouse movement
        groupY -= (y - mouseY) * 0.01f; // Change Y based on mouse movement
        mouseX = x;
        mouseY = y;
        glutPostRedisplay(); // Redraw the scene with the new positions
    }
    if (isRotating) {
        rotY += (x - mouseX) * 0.5f; // Rotate around Y axis
        rotX += (y - mouseY) * 0.5f; // Rotate around X axis
        mouseX = x;
        mouseY = y;
        glutPostRedisplay(); // Redraw the scene with the new rotation
    }
}


void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    setupLighting();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Interaction Lab with Lighting");

    init();
    glutReshapeFunc(reshape); // Register reshape callback for adjusting perspective
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register the keyboard handler
	glutSpecialFunc(keyboard2); // Register the special keyboard handler
    glutMouseFunc(mouse);       // Register the mouse handler
    glutMotionFunc(motion);     // Register the motion handler


    glutMainLoop();
    return 0;
}