#include "GL/freeglut.h";
#include "GL/gl.h"

float WinWid = 400.0;
float WinHei = 400.0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for(float i = -WinWid/2; i<= WinWid/2; i+=20.0) {
        glVertex2f(i, -WinHei/2);
        glVertex2f(i, WinHei/2);
    }
    for(float i = -WinHei/2; i<= WinHei/2; i+=20.0) {
        glVertex2f(-WinWid/2, i);
        glVertex2f(WinWid/2, i);
    }
    glEnd();
    glFlush();
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(50.0, -50.0, 0.0);
    glScalef(0.9, 0.9, 1.0);
    glRotatef(15, 0.0, 0.0, -1.0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 01");
    
    glutDisplayFunc(Draw);
    Initsialaize();
    glutMainLoop();
    
    return 0;
}

