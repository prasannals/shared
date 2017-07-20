#include<GL/glut.h>
#include<iostream>

#define HEIGHT 600
#define WIDTH 800


using namespace std;


float x0, y0, x1, y1, x2, y2, x3, y3;


void updatebuf(float x0, float y0, float x1, float y1, int *left, int *right){
  float m = (y1 - y0)/ (x1 - x0);

  int startY, endY;
  float startX;

  if(y0 < y1){
    startY = (int)(y0);
    endY = (int)(y1);

    startX = x0;
  }else{
    startY = (int)(y1);
    endY = (int)(y0);

    startX = x1;
  }

  // glColor3f(1,0,0);
  // glBegin(GL_POINTS);

  int i = 0;
  for(int i = startY; i <= endY; i++){
    // int x = (int)(startX + (i * m));

    float x = ((i - startY)/ m) + startX;
    i++;
    // glVertex2f(x, i);
    if(x < left[i]){
      left[i] = x;
    }

    if (x > right[i]){
      right[i] = x;
    }
  }

  // glEnd();
  //
  // glColor3f(0,0,0);
}

void writePixel(int x, int y){
  glBegin(GL_POINTS);
    glVertex2f(x, y);
  glEnd();
}

void scanline(float x0, float y0, float x1, float y1, float x2, float y2,
                        float x3, float y3){
  int left[HEIGHT], right[HEIGHT];

  for(int i = 0; i < HEIGHT; i++){
    left[i] = WIDTH;
    right[i] = 0;
  }
  cout << "update 1\n";
  updatebuf(x0, y0, x1, y1, left, right);
  cout << "update 2\n";
  updatebuf(x1, y1, x2, y2, left, right);
  cout << "update 3\n";
  updatebuf(x2, y2, x3, y3, left, right);
  cout << "update 4\n";
  updatebuf(x3, y3, x0, y0, left, right);

  // glBegin(GL_LINES);
  //   glVertex2f(x0, y0);
  //   glVertex2f(x1, y1);
  //   glVertex2f(x1, y1);
  //   glVertex2f(x2, y2);
  //   glVertex2f(x2, y2);
  //   glVertex2f(x3, y3);
  //   glVertex2f(x3, y3);
  //   glVertex2f(x0, y0);
  // glEnd();

  // for(int i = 0; i < HEIGHT; i++){
  //     writePixel(left[i], i );
  //     cout << left[i] << " : " << i << endl;
  // }

  for(int i = 0; i < HEIGHT; i++){
    for(int j = left[i]; j <= right[i]; j++){
      writePixel(j, i);
    }
  }
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
  x0 = 100;
  y0 = 100;

  x1 = 600;
  y1 = 150;

  x2 = 600;
  y2 = 600;

  x3 = 150;
  y3 = 550;
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

  scanline(x0, y0, x1, y1, x2, y2, x3, y3);

  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(0,0);

  glutCreateWindow("Scan line");

  glutDisplayFunc(display);
  init();
  getInput();
  glutMainLoop();
  return 0;
}
