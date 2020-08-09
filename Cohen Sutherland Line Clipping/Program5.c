#include<GL/gl.h> 
#include<GL/glut.h> 
#include<stdio.h> 
#include<stdbool.h>

double xmin=50,ymin=50,xmax=100,ymax=100; 
const int RIGHT=8;
const int LEFT=2; 
const int TOP=4; 
const int BOTTOM=1;

int ComputeOutCode(double x,double y)
{
  int code=0;
  if(y>ymax) 
    code|=TOP;
  else if(y<ymin) 
    code|=BOTTOM; 
  if(x>xmax) 
    code|=RIGHT;
  else if(x<xmin) 
    code|=LEFT; 
  return code;
}

void CohenSutherlandLineClipAndDraw(double x0,double y0,double x1,double y1)
{
  int outcode0,outcode1,outcodeOut; 
  bool accept=false;
  bool done=false; 
  outcode0=ComputeOutCode(x0,y0); 
  outcode1=ComputeOutCode(x1,y1); 
  do
  {
    if(!(outcode0|outcode1))
    {
      accept=true; 
      done=true;
    }
    else if(outcode0 & outcode1)
    {
      done=true;
    }
    else
    {
      double x,y; 
      outcodeOut=outcode0?outcode0:outcode1; 
      if(outcodeOut & TOP)
      {
        x=x0+(x1-x0)*(ymax-y0)/(y1-y0); 
        y=ymax;
      }
      else if(outcodeOut & BOTTOM)
      {
        x=x0+(x1-x0)*(ymin-y0)/(y1-y0); 
        y=ymin;
      }
      else if(outcodeOut & RIGHT)
      {
        y=y0+(y1-y0)*(xmax-x0)/(x1-x0); 
        x=xmax;
      }
      else
      {
        y=y0+(y1-y0)*(xmin-x0)/(x1-x0); 
        x=xmin;
      }
      if(outcodeOut==outcode0)
      {
        x0=x; 
        y0=y;
        outcode0=ComputeOutCode(x0,y0);
      }
      else
      {
        x1=x; 
        y1=y;
        outcode1=ComputeOutCode(x1,y1);
      }
    }
  }while(!done); 
  if(accept)
  {
    glTranslatef(200,200,0); 
    glScalef(2,2,1); 
    glColor3f(0,0,1); 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(xmin,ymin); 
    glVertex2f(xmax,ymin); 
    glVertex2f(xmax,ymax); 
    glVertex2f(xmin,ymax); 
    glEnd();
    glColor3f(1,0,0); 
    glBegin(GL_LINES); 
    glVertex2d(x0,y0); 
    glVertex2d(x1,y1); 
    glEnd();
  }
}

void display()
{
  double x0=60,y0=60,x1=80,y1=80; 
  glClearColor(1.0,1.0,1.0,1.0); 
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0,0.0,0.0); 
  glBegin(GL_LINES); 
  glVertex2d(x0,y0); 
  glVertex2d(x1,y1);
  glEnd(); 
  glColor3f(0.0,0.0,1.0); 
  glBegin(GL_LINE_LOOP); 
  glVertex2f(xmin,ymin); 
  glVertex2f(xmax,ymin); 
  glVertex2f(xmax,ymax); 
  glVertex2f(xmin,ymax); 
  glEnd();
  CohenSutherlandLineClipAndDraw(x0,y0,x1,y1); 
  glFlush();
}

void myinit()
{
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(0,1500,0,1500);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char**argv)
{
  glutInit(&argc,argv); 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
  glutInitWindowSize(500,500); 
  glutInitWindowPosition(0,0);
  glutCreateWindow("Cohen Sutherland Line Clipping - Burla Sai Teja"); 
  glutDisplayFunc(display);
  myinit(); 
  glutMainLoop();
}
