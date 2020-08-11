#include<GL/glut.h> 
#include<stdio.h>

float v[4][3]={{-1,-1,-1},{0,1,-1},{0,0,1},{1,-1,-1}};
int m; 

void init()
{
  glClearColor(0,0,0,1); 
  glMatrixMode(GL_PROJECTION); 
  glOrtho(-2,2,-2,2,-10,10);
  glMatrixMode(GL_MODELVIEW);
}

void triangle(float *a,float *b,float *c)
{
  glBegin(GL_TRIANGLES); 
  glColor3f(0.9,0.45,0.45);
  glVertex3fv(a); 
  glColor3f(0.45,0.9,0.45);
  glVertex3fv(b); 
  glColor3f(0.45,0.45,0.9);
  glVertex3fv(c); 
  glEnd();
}

void divide_triangle(float *a,float *b,float *c, int m)
{
  float v1[3],v2[3],v3[3]; 
  if(m>0)
  {
    for(int i=0;i<3;i++)
    {
      v1[i]=(a[i]+c[i])/2;
      v2[i]=(a[i]+b[i])/2;
      v3[i]=(b[i]+c[i])/2;
    }
    divide_triangle(a,v1,v2,m-1); 
    divide_triangle(c,v1,v3,m-1); 
    divide_triangle(b,v2,v3,m-1);
  }
  else
    triangle(a,b,c);
}
 
void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1,0,0); 
  divide_triangle(v[0],v[1],v[2],m); 
  glColor3f(0,1,0); 
  divide_triangle(v[1],v[2],v[3],m); 
  glColor3f(0,0,1); 
  divide_triangle(v[0],v[1],v[3],m); 
  glColor3f(1,0,1); 
  divide_triangle(v[0],v[2],v[3],m); 
  glFlush();
}

int main(int argc,char **argv)
{
  printf("no of division?"); 
  scanf("%d",&m); 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH); 
  glutInitWindowSize(500,500);
  glutCreateWindow("Sierpinski (Gasket) - Burla Sai Teja"); 
  init();
  glutDisplayFunc(display); 
  glEnable(GL_DEPTH_TEST); 
  glutMainLoop();
}
