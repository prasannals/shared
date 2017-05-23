#include<iostream>
#include<GL/glut.h>
#define X 400
#define Y 400
#define Z 400

using namespace std;

float v[][3] = {{0,0,0}, {1,0,0}, {1,1,0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1} , {1, 1, 1}, {0,1, 1}};
float color[][3] = {{0,0,0}, {1,0,0}, {1,1,0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1} , {1, 1, 1}, {0,1, 1}};
float angle[] = {0,0,0};
int  axis = 0;

void drawRect(int a, int b, int c, int d){
  glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(v[a]);
    glColor3fv(color[b]);
    glVertex3fv(v[b]);
    glColor3fv(color[c]);
    glVertex3fv(v[c]);
    glColor3fv(color[d]);
    glVertex3fv(v[d]);
  glEnd();
}

void drawCube(){
  drawRect(0, 1, 2, 3);
  drawRect(2, 1, 5, 6);
  drawRect(6, 5, 4, 7);
  drawRect(7, 4, 0, 3);
  drawRect(0, 4, 5, 1);
  drawRect(6, 2, 3, 7);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glScalef(100,100,100);
  glRotatef(angle[0], 1, 0, 0);
  glRotatef(angle[1], 0, 1, 0);
  glRotatef(angle[2], 0, 0, 1);
  drawCube();
  glFlush();
  //glutSwapBuffers();

  glutPostRedisplay();
}

void spinCube(){
  if(angle[axis] == 360)
    angle[axis] = 1;
  else
    angle[axis] += 1;

}

void keyboardFunc(unsigned char key, int x, int y){
  if(key == 'x')
    axis = 0;
  else if(key == 'y')
    axis = 1;
  else if(key == 'z')
    axis = 2;
}

void myreshape(int w, int h)
{

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

void init(){

  glMatrixMode(GL_PROJECTION);
  glOrtho(-X, X, -Y, Y, -Z, Z);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize(X * 2, Y * 2);

  glutCreateWindow("Spinning cube");
  //glutReshapeFunc(myreshape);
  glutDisplayFunc(display);
  glutIdleFunc(spinCube);
  glutKeyboardFunc(keyboardFunc);
  init();
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glEnable(GL_DEPTH_TEST);

  glutMainLoop();
  return 0;
}
