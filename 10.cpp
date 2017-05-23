#include<GL/glut.h>
#include<iostream>
using namespace std;
#define WIDTH 800
#define HEIGHT 600

void drawMesh(float initX, float initY, float dx, float dy, int numLines){
  float finalX = initX + (dx * (numLines - 1));
  float finalY = initY + (dy * (numLines - 1));


  for(int i = 0; i < numLines; i++){
    glBegin(GL_LINES);
      glVertex3f(initX, initY + (i * dy), 0);
      glVertex3f(finalX, initY + (i * dy), 0);
    glEnd();
  }

  for(int i = 0; i < numLines; i++){
    glBegin(GL_LINES);
      glVertex3f(initX + (i * dx), initY, 0);
      glVertex3f(initX + (i * dx), finalY, 0);
    glEnd();
  }

}

void display(void){
  drawMesh(10,10,50,50,10);
  glFlush();
}

void reshape(int w, int h)
{
  /* save new screen dimensions */
  int width = (GLdouble) w;
  int height = (GLdouble) h;

  /* tell OpenGL to use the whole window for drawing */
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  /* do an orthographic parallel projection with the coordinate
     system set to first quadrant, limited by screen/window size */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, width, 0.0, height, -1.f, 1.f);

  return;
}


int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Mesh");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
