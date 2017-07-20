#include<iostream>
#include<GL/glut.h>

using namespace std;

void wall(float thick){
  glPushMatrix();
    glTranslatef(0.5, thick/2.0, 0.5);
    glScalef(1, thick, 1);
    glutSolidCube(1);
  glPopMatrix();
}

void tableLeg(float legLen, float legThick){
  glPushMatrix();
    glTranslated(0, legLen/2 , 0);
    glScalef(legThick, legLen, legThick);
    glutSolidCube(1.0);
  glPopMatrix();
}

void table(float topWid, float topThick, float legThick, float legLen){
  glPushMatrix();
    glTranslatef(0, legLen, 0);
    glScalef(topWid, topThick, topWid);
    glutSolidCube(1.0);
  glPopMatrix();

   float dist = ((0.95 * topWid) / 2 ) - (legThick / 2);

   glPushMatrix();
    glTranslatef(dist, 0, dist);
    tableLeg(legLen, legThick);
    glTranslatef(0, 0, -2 * dist);
    tableLeg(legLen, legThick);
    glTranslatef(-2 * dist, 0, 2 * dist);
    tableLeg(legLen, legThick);
    glTranslatef(0, 0, -2 * dist);
    tableLeg(legLen, legThick);
  glPopMatrix();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

  float m_ambient[4] = {0.7, 0.7, 0.7, 1};
  float m_diffuse[4] = {0.5, 0.5, 0.5, 1};
  float m_specular[4] = {1, 1, 1, 1};
  float m_shininess = 50.0;

  glMaterialfv(GL_FRONT, GL_AMBIENT, m_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, m_shininess);

  float l_dir[4] = {2.4, 3.4, -2, 0};
  float l_diffuse[4] = {0.7, 0.7, 0.7, 1};

  glLightfv(GL_LIGHT0, GL_POSITION, l_dir);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, l_diffuse);

  gluLookAt(0,1.3, -1, 0, 0, 0, -.5, 1, 0);

  glPushMatrix();
    glTranslatef(-.4, -.2, 0);
    wall(0.02);

    glPushMatrix();
      glRotated(90, 0, 0, 1);
      wall(0.02);
    glPopMatrix();

    glPushMatrix();
      glRotated(-90, 1, 0, 0);
      wall(0.02);
    glPopMatrix();

  glPopMatrix();

  glPushMatrix();
    glTranslatef(0, 0.35, 0);
    glRotated(30, 0, 1, 0);
    glutSolidTeapot(0.08);
  glPopMatrix();

  glPushMatrix();
    table(0.6, 0.02, 0.02, 0.3);
  glPopMatrix();


  glFlush();
}


int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Teapot");

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}
