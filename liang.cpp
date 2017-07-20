#include<GL/glut.h>
#include<iostream>

using namespace std;

double ymax, ymin, xmax, xmin;

double x2, y2, x1, y1;

double aTop, aBottom, aRight, aLeft;

double clipX, clipY;

void calcAlphas(double x1, double y1, double x2, double y2){
  aTop = (ymax - y1)/(y2 - y1);
  aBottom = (ymin - y1)/(y2 - y1);

  aRight = (xmax - x1)/(x2 - x1);
  aLeft = (xmin - x1)/(x2 - x1);
}

bool cliptest(double alpha){
  clipX = (1 - alpha) * x1 + (alpha * x2);
  clipY = (1 - alpha) * y1 + (alpha * y2);

  if (clipX >= xmin && clipX <= xmax && clipY >= ymin && clipY <= ymax)
    return true;
  else
    return false;
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
  glEnd();

  glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
  glEnd();

  glTranslatef(800, 0,0);

  glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
  glEnd();

  calcAlphas(x1, y1, x2, y2);

  glBegin(GL_LINES);
    if(cliptest(aTop))
      glVertex2f(clipX, clipY);

      if(cliptest(aRight))
        glVertex2f(clipX, clipY);

        if(cliptest(aLeft))
          glVertex2f(clipX, clipY);

          if(cliptest(aBottom))
            glVertex2f(clipX, clipY);

  glEnd();

  glFlush();
}

void init(){
  glClearColor(1,1,1,1);
  glColor3f(0,0,0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-200, 1800, -200, 1800, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void getInput(){
  ymax = 600;
  ymin = 200;
  xmax = 600;
  xmin = 200;

  x1 = 100;
  y1 = 200;
  x2 = 700;
  y2 = 700;
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(0,0);

  glutCreateWindow("Liang Barsky");

  glutDisplayFunc(display);
  init();
  getInput();
  glutMainLoop();
  return 0;
}
