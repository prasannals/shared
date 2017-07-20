#include<GL/glut.h>
#include<iostream>

using namespace std;


double ymax, ymin, xmax, xmin;
double x2, y2, x1, y1;




class OutCode{

public:
  bool right, left, bottom, top;

  OutCode(double x, double y){
    this->initialize(x, y);
  }

  void initialize(double x, double y){
    right = false;
    left = false;
    bottom = false;
    top = false;

    if(x > xmax)
      right = true;
    else if(x < xmin)
      left = true;

    if(y > ymax)
      top = true;
    else if(y < ymin)
      bottom = true;
  }

  bool isZero(){
    if(right == false && left == false && top == false && bottom == false)
      return true;
    else
      return false;
  }

  bool andIsZero(OutCode &o){
    cout << "is zero?\n";
    print();
    o.print();
    cout << (right & o.right) << endl;
    cout << (left & o.left) << endl;

    cout <<  (top & o.top) << endl;
    cout << (bottom & o.bottom) << endl;

    if( !(right & o.right) && !(left & o.left) &&
      !(top & o.top) && !(bottom & o.bottom) )
      return true;
    else
      return false;
  }

  void print(){
    cout << left << right << top << bottom << endl;
  }

};



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

  OutCode p1(x1, y1), p2(x2, y2);

  p1.print();
  p2.print();

  if(p1.isZero() && p2.isZero()){
    //line inside clipping region
    // draw it
    glBegin(GL_LINES);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
    glEnd();
  }
  else if(p1.isZero() && (p2.isZero() == false)){
    glBegin(GL_LINES);
      glVertex2f(x1, y1);

      calcAlphas(x1, y1, x2, y2);

      if(p2.top && cliptest(aTop))
        glVertex2f(clipX, clipY);

      if(p2.right && cliptest(aRight))
        glVertex2f(clipX, clipY);

      if(p2.left && cliptest(aLeft))
        glVertex2f(clipX, clipY);

      if(p2.bottom && cliptest(aBottom))
        glVertex2f(clipX, clipY);

    glEnd();
  }else if(p1.andIsZero(p2) == false){
    //ignore it
    cout << "ignoring" << endl;
  }else if(p1.andIsZero(p2)){
    calcAlphas(x1, y1, x2, y2);

    cout << "Brute force\n";

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
  }

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
