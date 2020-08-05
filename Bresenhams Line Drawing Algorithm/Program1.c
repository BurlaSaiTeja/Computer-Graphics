#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
int xx0,xx1,yy0,yy1; 
float m;

void init()
{
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(-250,250,-250,250);
  glMatrixMode(GL_MODELVIEW);
}

void swap(int *a,int *b)
{
  int temp; 
  temp=*a;
  *a=*b;
  *b=temp;
}

void draw_pt(int x,int y)
{
  glColor3f(1,0,0); 
  glBegin(GL_POINTS); 
  glVertex2f(x,y); 
  glEnd();
}

void linesdrawing(int xx0,int yy0,int xx1,int yy1)
{
  if(m<1)
  {
    if(xx0>xx1)
    {
      swap(&xx0,&xx1); 
      swap(&yy0,&yy1);
    }
    int dx=abs(xx1-xx0); 
    int dy=abs(yy1-yy0); 
    int p=(2*dy)-dx;
    int pneg=2*dy;
    int ppos=2*(dy-dx); 
    int x=xx0,y=yy0; 
    draw_pt(x,y); 
    while(x<xx1)
    {
      if(p<0)
         p+=pneg;
      else
      {
        if(m>0)
          y++;
        else
          y--;
        p+=ppos;
      } 
      x++;
      draw_pt(x,y);
    }
  }
  if(m>=1)
  {
    if(yy0>yy1)
    {
      swap(&xx0,&xx1); 
      swap(&yy0,&yy1);
    }
    int dx=abs(xx1-xx0); 
    int dy=abs(yy1-yy0); 
    int p=(2*dx)-dy;
    int pneg=2*dx;
    int ppos=2*(dx-dy); 
    int x=xx0,y=yy0; 
    draw_pt(x,y); 
    while(y<yy1)
    {
      if(p<0)
        p+=pneg;
      else
      {
        if(m>0)
          x++;
        else
          x--;
        p+=ppos;  
      } 
      y++;
      draw_pt(x,y);
    }
  }
}

void display()
{
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT); 
  linesdrawing(xx0,yy0,xx1,yy1); 
  glFlush();
}

void main(int argc,char **argv)
{
  printf("Enter the 2 points : \n"); 
  scanf("%d",&xx0);
  scanf("%d",&yy0);
  scanf("%d",&xx1);
  scanf("%d",&yy1);
  m=(yy1-yy0)/(float)(xx1-xx0); 
  glutInit(&argc,argv); 
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE); 
  glutInitWindowSize(500,500); 
  glutInitWindowPosition(0,0);
  glutCreateWindow("Bresenham's Line Drawing - Burla Sai Teja"); 
  init();
  glutDisplayFunc(display); 
  glutMainLoop();
}
