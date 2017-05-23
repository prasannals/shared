#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

float radian(float angle){
  return angle * (3.14 / 180);
}

void drawCircle(float radius, int resolution){
//  y = radius * sin(angle)
//  x = radius * cos(angle)
// 180 degree = pi radian
// 1 degree = (3.14 / 180) radian
// x degree = x * (3.14 / 180) radian
  float incr = (360.0/ resolution);

  glBegin(GL_LINE_LOOP);
    for(float i = 0; i <= 360; ){
      float y = radius * sin(radian(i));
      float x = radius * cos(radian(i));
      //cout << i << " " << x << " " << y << endl;
      glVertex3f(x, y, 0);
      i += incr;
    }
  glEnd();
}

void drawRect(float width){
  glBegin(GL_LINE_LOOP);
    glVertex3f(0, 0, 0);
    glVertex3f(width, 0, 0);
    glVertex3f(width, width, 0);
    glVertex3f(0, width, 0);
  glEnd();
}

void drawCircleThingi(float height, int resolution){
  float incr = height / resolution;

  glPushMatrix();
  for(float i = 0; i < height; ){
    drawCircle(100, 360);
    i += incr;
    glTranslatef(0 , incr, 0);
  }
  glPopMatrix();
}

void drawCubeThingi(float height, int resolution){
  float incr = height / resolution;
  glPushMatrix();

    for(float i = 0; i < height; ){
      drawRect(200);
      cout << i << endl;
      glTranslatef(incr, incr, 0);
      i += incr;
    }
  glPopMatrix();
}

void display(){
  glColor3f(1,0,0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  glTranslatef(200, 200, 0);
  // glScalef(200, 200, 1);
  //
  // drawRect();
  drawCircleThingi(300, 50);

  glTranslatef(200, 0, 0);
  drawCubeThingi(100, 50);

  glFlush();
}

void init(){
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glOrtho(0, 800, 0, 800, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(200,200);
  glutCreateWindow("cirlce and rect thingi");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
