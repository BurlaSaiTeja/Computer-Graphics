#include<stdlib.h> 
#include<GL/gl.h> 
#include<GL/glut.h>

float vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
float theta[]={0.0,0.0,0.0}; 
int axis=2;

void polygon(int a,int b,int c,int d)
{
  glBegin(GL_POLYGON); 
  glColor3f(0.9,0.3,0.3); 
  glVertex3fv(vertices[a]); 
  glColor3f(0.3,0.9,0.3); 
  glVertex3fv(vertices[b]); 
  glColor3f(0.3,0.3,0.9); 
  glVertex3fv(vertices[c]); 
  glColor3f(0.9,0.9,0.3); 
  glVertex3fv(vertices[d]); 
  glEnd();
}

void colorcube()
{
  polygon(0,3,2,1);
  polygon(2,3,7,6);
  polygon(0,4,7,3);
  polygon(1,2,6,5);
  polygon(4,5,6,7);
  polygon(0,1,5,4);
}

void display(void)
{    
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity(); 
  glRotatef(theta[0],1.0,0.0,0.0);
  glRotatef(theta[1],0.0,1.0,0.0);
  glRotatef(theta[2],0.0,0.0,1.0); 
  colorcube();
  glFlush(); 
  glutSwapBuffers();
}

void spinCube()
{
  theta[axis]+=0.1; 
  if(theta[axis]>360.0)
    theta[axis]-=360.0; 
  glutPostRedisplay();
}

void mouse(int btn,int state,int x,int y)
{
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    axis=0; 
  if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
    axis=1; 
  if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
    axis=2;
}

void myReshape(int w,int h)
{
  glViewport(0,0,w,h); 
  glMatrixMode(GL_PROJECTION); 
  glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv); 
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 
  glutInitWindowSize(500,500);
  glutCreateWindow("Rotating Cube - Burla Sai Teja"); 
  glutReshapeFunc(myReshape); 
  glutDisplayFunc(display);
  glutIdleFunc(spinCube); 
  glutMouseFunc(mouse); 
  glEnable(GL_DEPTH_TEST); 
  glutMainLoop();
}
