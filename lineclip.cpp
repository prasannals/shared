#include<GL/glut.h>
#include<iostream>
#include<vector>
#define NAN -9999999
using namespace std;

class Line{
public:
  float slope, intercept;
  float x1, y1, x2, y2;
  bool xIntercept, yIntercept;

  Line(float slope, float intercept){
    this->slope = slope;
    this->intercept = intercept;
  }

  Line(float x1, float y1, float x2, float y2){
    this->init(x1, y1, x2, y2);
  }

  Line(){}

  void init(float x1, float y1, float x2, float y2){
    this->slope = (y1 - y2) / (x1 - x2);

    this->intercept = (y1 - (this->slope * x1));
    if(x1 == x2){
      xIntercept = true;
    }else{
      xIntercept = false;
    }

    if(y1 == y2){
      yIntercept = true;
    }else{
      yIntercept = false;
    }

    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }

  float calcY(float x){
    return (slope * x) + intercept;
  }

  float calcX(float y){
    return (y - intercept) / slope;
  }

  void calcIntersection(Line &line2, vector<float> &vec){
    float subSlope = this->slope - line2.getSlope();
    float subIntercept = this->intercept - line2.getIntercept();

    float x = NAN;
    float y = NAN;
    if(line2.xIntercept){
      x = line2.x1;
      y = calcY(x);
    }else if(line2.yIntercept){
      y = line2.y1;
      x = calcX(y);
    }else if(subSlope != 0){
       x = -subIntercept / subSlope;
       y = this->calcY(x);
    }

    vec.push_back(x);
    vec.push_back(y);
  }

  float getSlope(){
    return slope;
  }

  float getIntercept(){
    return intercept;
  }
};

Line line, leftt, rightt, top, bottom;
float x0, y0, x1, y1, x2, y2, x3, y3;
float lx0, ly0, lx1, ly1;

bool between(float x, float startp, float endp){
  if(startp > endp){
    if(x <= startp && x >= endp)
      return true;
  }else{
    if(x >= startp && x <= endp)
      return true;
  }

  return false;
}

void drawIntersection(Line &line1, Line &line2){
  std::vector<float> v;
  line1.calcIntersection(line2, v);
  cout << v.at(0) << " " << line2.x1 << " " << line2.x2 << endl;
  cout << v.at(1) << " " << line2.y1 << " " << line2.y2 << endl;
  cout << endl;
  if( between(v.at(0), line2.x1, line2.x2) && between(v.at(1), line2.y1, line2.y2) ){
    glBegin(GL_POINTS);
      glVertex3f(v.at(0), v.at(1), 0);
    glEnd();

    cout << "Success!\n";
  }

}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);

  glBegin(GL_LINE_LOOP);
    glVertex3f(x0, y0, 0);
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);
    glVertex3f(x3, y3, 0);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(lx0, ly0, 0 );
    glVertex3f(lx1, ly1, 0);
  glEnd();


  glColor3f(0,1,0);
  glPointSize(4.0);
  drawIntersection(line, leftt);
  drawIntersection(line, rightt);
  drawIntersection(line, top);
  drawIntersection(line, bottom);

  glFlush();
}


void init(){
  glClearColor(1,1,1,1);
  glMatrixMode(GL_PROJECTION);
  glOrtho(0, 500, 0, 500, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void initInput(){

  cout << "Enter x0\n";
  cin >> x0;
  cout << "Enter y0\n";
  cin >> y0;
  cout << "Enter x1\n";
  cin >> x1;
  cout << "Enter y1\n";
  cin >> y1;
  cout << "Enter x2\n";
  cin >> x2;
  cout << "Enter y2\n";
  cin >> y2;
  cout << "Enter x3\n";
  cin >> x3;
  cout << "Enter y3\n";
  cin >> y3;

  leftt.init(x0, y0, x3, y3);
  bottom.init(x0, y0, x1, y1);
  rightt.init(x1, y1, x2, y3);
  top.init(x2, y2, x3, y3);

  cout << "Enter the x0 and y0 of line\n";
  cin >> lx0;
  cin >> ly0;

  cout << "Enter the x1 and y1 of line\n";
  cin >> lx1;
  cin >> ly1;

  line.init(lx0, ly0, lx1, ly1);
}

int main(int argc, char *argv[]) {
  initInput();

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Line test");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
