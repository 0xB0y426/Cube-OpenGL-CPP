// coding a cube in cpp using OpenGL
// By Raidboy

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat angle = 0.0f;

float white[] = {1.0f, 1.0f, 1.0f};

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    glColor3f(white[0], white[1], white[2]);
    glutWireCube(1.0f);

    glutSwapBuffers();

    angle += 0.5f;

    if (angle > 360.0f) angle -= 360.0f;
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cube rotating | OpenGL");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}
