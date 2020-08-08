#include<stdlib.h> 
#include<GL/glut.h> 

GLfloat vertices[][3]={
{1.5,2.0,-0.5},{0.5,2.0,-0.5}, {0.5,1.0,-0.5},{1.5,1.0,-0.5},{1.5,2.0,0.5},
{0.5,2.0,0.5},{0.5,1.0,0.5},{1.5,1.0,0.5},
{1.5,0.5,-0.5},{0.5,0.5,-0.5},{0.5,-0.5,-0.5}, {1.5,-0.5,-0.5},{1.5,0.5,0.5}, {0.5,0.5,0.5},{0.5,-
0.5,0.5},{1.5,-0.5,0.5},
{1.5,-1.0,-0.5}, {0.5,-1.0,-0.5},{0.5,-2.0,-0.5},{1.5,-2.0,-0.5},{1.5,-1.0,0.5}, {0.5,-1.0,0.5},{0.5,-
2.0,0.5} ,{1.5,-2.0,0.5},
{-1.5,2.0,-0.5},{-0.5,2.0,-0.5}, {-0.5,1.0,-0.5},{-1.5,1.0,-0.5},{-1.5,2.0,0.5}, {-0.5,2.0,0.5},{-
0.5,1.0,0.5},{-1.5,1.0,0.5},
{-1.5,0.5,-0.5},{-0.5,0.5,-0.5},{-0.5,-0.5,-0.5}, {-1.5,-0.5,-0.5},{-1.5,0.5,0.5}, {-0.5,0.5,0.5},{-
0.5,-0.5,0.5},{-1.5,-0.5,0.5},
{-1.5,-1.0,-0.5}, {-0.5,-1.0,-0.5},{-0.5,-2.0,-0.5},{-1.5,-2.0,-0.5},{-1.5,-1.0,0.5}, {-0.5,-1.0,0.5},{-
0.5,-2.0,0.5} ,{-1.5,-2.0,0.5}
};
 
GLfloat colors[][3]={
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5},
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5},
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5},
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5},
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5},
{0.0,0.0,0.0},{0.5,0.0,0.0}, {0.5,0.5,0.0},{0.0,0.5,0.0},{0.0,0.0,0.5},
{0.5,0.0,0.5},{0.5,0.5,0.5},{0.0,0.5,0.5}};

void polygon(int a, int b, int c, int d) 
{ 
  glBegin(GL_POLYGON); 
  glColor3fv(colors[a]); 
  glVertex3fv(vertices[a]); 
  glColor3fv(colors[b]); 
  glVertex3fv(vertices[b]); 
  glColor3fv(colors[c]); 
  glVertex3fv(vertices[c]); 
  glColor3fv(colors[d]); 
  glVertex3fv(vertices[d]);
  glEnd();
}

void colorcube() 
{ 
  polygon(0, 1, 2, 3);
  polygon(3, 4, 7, 0);
  polygon(0, 1, 7, 4);
  polygon(4, 7, 6, 5);
  polygon(5, 1, 3, 6);
  polygon(6, 7, 3, 2);

  polygon(8, 9, 10, 11);
  polygon(11, 15, 12, 8);
  polygon(8, 9, 15, 12);
  polygon(12, 15, 14, 13);
  polygon(13, 9, 11, 14);
  polygon(14, 15, 11, 10);

  polygon(16, 17, 18, 19);
  polygon(19, 23, 20, 16);
  polygon(16, 17, 23, 20);
  polygon(20, 23, 22, 21);
  polygon(21, 17, 19, 22);
  polygon(22, 23, 19, 18);

  polygon(24, 25, 26, 27);
  polygon(27, 28, 31, 24);
  polygon(24, 25, 31, 28);
  polygon(28, 31, 30, 29);
  polygon(29, 25, 27, 30);
  polygon(30, 31, 27, 26);

  polygon(32, 33, 34, 35);
  polygon(35, 36, 39, 32);
  polygon(32, 33, 39, 36);
  polygon(36, 39, 38, 37);
  polygon(37, 33, 35, 38);
  polygon(38, 39, 35, 34);

  polygon(40, 41, 42, 43);
  polygon(43, 44, 47, 40);
  polygon(40, 41, 47, 44);
  polygon(44, 47, 46, 45);
  polygon(45, 41, 43, 46);
  polygon(46, 47, 43, 42);
}

static GLfloat theta[] = { 0.0, 0.0,  0.0 };
static GLint axis = 2;
static GLdouble viewer[] = { 0.0, 0.0, 5.0 };

void display(void) 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 0.5, 0.0);
  glRotatef(theta[0], 0.5, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 0.5, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 0.5); 
  colorcube();
  glFlush(); 
  glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y) 
{
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    axis = 0;
  if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
    axis = 1; 
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
    axis = 2; 
  theta[axis] += 1.0;
  if (theta[axis] > 360.0) 
    theta[axis] -= 360.0; 
  display();
}

void keys(unsigned char key, int x, int y) 
{ 
  if (key == 'x') 
    viewer[0] -= 0.5;
  if (key == 'X') 
    viewer[0] += 0.5; 
  if (key == 'y') 
    viewer[1] -= 0.5; 
  if (key == 'Y') 
    viewer[1] += 0.5; 
  if (key == 'z') 
    viewer[2] -= 0.5; 
  if (key == 'Z') 
    viewer[2] += 0.5; 
  display();
}

void myReshape(int w, int h) 
{ 
  glViewport(0, 0, w, h); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  if (w <= h) 
    glFrustum(-1.0, 1.0, -1.0 * (GLfloat) h / (GLfloat) w, 1.0 * (GLfloat) h / (GLfloat) w, 1.0, 20.0);
  else 
    glFrustum(-1.0, 1.0, -1.0 * (GLfloat) w / (GLfloat) h, 1.0 * (GLfloat) w / (GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char ** argv) 
{ 
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
  glutInitWindowSize(500, 500);
  glutCreateWindow("Cube Perspective - Burla Sai Teja"); 
  glutReshapeFunc(myReshape); 
  glutDisplayFunc(display);
  glutMouseFunc(mouse); 
  glutKeyboardFunc(keys); 
  glEnable(GL_DEPTH_TEST); 
  glutMainLoop();
}
