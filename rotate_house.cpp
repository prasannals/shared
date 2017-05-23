#include<GL/glut.h>
#include<iostream>
#define progName "Rotate House"

using namespace std;

float angle;

void drawHouse(){
  glBegin(GL_LINE_LOOP);
    glVertex3f(0,0,0);
    glVertex3f(100, 0, 0);
    glVertex3f(100, 100, 0);
    glVertex3f(0, 100, 0);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex3f(40, 0, 0);
    glVertex3f(60, 0, 0);
    glVertex3f(60, 60, 0);
    glVertex3f(40, 60, 0);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex3f(0, 100, 0);
    glVertex3f(50, 150, 0);
    glVertex3f(100, 100, 0);
  glEnd();
}


void display(){
  glColor3f(1,0,0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(200, 200, 0);
  glScalef(2,2,1);
  drawHouse();

  glRotatef(angle, 0, 0, 1);
  drawHouse();

  glFlush();
}

void init(){
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 600, 0, 600, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char *argv[]) {
  cout << "Enter angle : ";
  cin >> angle;

  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(200,200);
  glutCreateWindow(progName);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
