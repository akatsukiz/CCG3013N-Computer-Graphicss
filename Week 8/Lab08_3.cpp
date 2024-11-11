#include <GL/glut.h>

// Light position and properties
GLfloat light_position[] = {2.0, 2.0, 1.0, 0.0};
GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};  // Increased ambient light

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    // Enable lighting
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Material properties
    GLfloat emission_mtrl[] = {0.8, 0.0, 0.0, 1.0};
    GLfloat ambient_mtrl[] = {0.8, 0.0, 0.0, 1.0};    // Increased ambient
    GLfloat diffuse_mtrl[] = {0.8, 0.0, 0.0, 1.0};
    GLfloat specular_mtrl[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambient_and_diffuse_mtrl[] = {0.8, 0.0, 0.0, 1.0};
    GLfloat no_material[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {100.0};
    
    glPushMatrix();
    glTranslatef(-4.0, 0.0, -10.0);
    
    // 1. GL_EMISSION
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_material);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, no_material);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_mtrl);
    glutSolidSphere(0.7, 30, 30);
    
    // 2. GL_AMBIENT only
    glTranslatef(2.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_material);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_mtrl);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, no_material);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
    glutSolidSphere(0.7, 30, 30);
    
    // 3. GL_DIFFUSE only
    glTranslatef(2.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_material);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_mtrl);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
    glutSolidSphere(0.7, 30, 30);
    
    // 4. GL_SPECULAR with some diffuse
    glTranslatef(2.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_material);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_mtrl);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_mtrl);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glutSolidSphere(0.7, 30, 30);
    
    // 5. GL_AMBIENT_AND_DIFFUSE
    glTranslatef(2.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient_and_diffuse_mtrl);
    glutSolidSphere(0.7, 30, 30);
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Task 3 - Material Properties Demo");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}