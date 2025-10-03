#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background color
    glEnable(GL_DEPTH_TEST);         // Enable depth testing
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-0.5f, -0.5f, -5.0f); // Move back and center

    // Draw 3D bar (cuboid)
    glColor3f(0.2, 0.6, 1.0); // Blue
    glutSolidCube(1.0);       // A cube with side 1

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Bar in C using OpenGL");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}