#include<GL/glut.h> 
#include<math.h> 
#include<stdio.h>

int xx0,yy0,xx1,yy1,x2,y2,x3,y3,le[500],re[500],flag=0;

void edge(int a, int b, int c, int d)
{
  if(d<b)
  {
    int temp = a; 
    a = c;
    c = temp; 
    temp = b; 
    b = d;
    d = temp;
  }
  int x = a, y=b;
  int m = (d-b)/(c-a); 
  for(int i = b;i<=d;i++)
  {
    if(x<le[i])
      le[i] = x;
    if(x>re[i])
      re[i] = x;
    y++;
    x+=m;
  }
}

void scanfill()
{
  for(int i = 0;i<500;i++)
  {
    le[i] = 500;
    re[i] = 0;
  }
  edge(xx0,yy0, xx1,yy1); 
  edge(xx1,yy1, x2,y2); 
  edge(x2,y2, x3,y3); 
  edge(x3,y3, xx0,yy0); 
  for(int i=0;i<500;i++)
  {
    if(le[i] <re[i])
    {
      for(int j = le[i]; j<re[i]; j++)
      { 
        glColor3f(0,0,1); 
        glBegin(GL_POINTS); 
        glVertex2f(j, i); 
        glEnd();
      }
    }
  }
}

void display()
{
  glClearColor(1,1,1,1); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,0); 
  glBegin(GL_LINE_LOOP); 
  glVertex2f(xx0, yy0); 
  glVertex2f(xx1, yy1); 
  glVertex2f(x2, y2); 
  glVertex2f(x3, y3); 
  glEnd();
  if(flag==1)
    scanfill();
  glFlush();
}

void init()
{
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(0,500,0,500);
  glMatrixMode(GL_MODELVIEW);
}

void menuDisplay(int ch)
{ 
  switch(ch)
  {
    case 1: flag = 1;
            break;
    case 2: flag = 0;
            break;
    case 3: exit(0);
  } 
  display();
}

void main(int argC, char **argV)
{
  glutInit(&argC, argV);
  printf("Enter 1st point coordinate:"); 
  scanf("%d%d", &xx0,&yy0); 
  printf("Enter 2nd point coordinate:");
  scanf("%d%d", &xx1,&yy1); 
  printf("Enter 3st point coordinate:"); 
  scanf("%d%d", &x2,&y2); 
  printf("Enter 4nd point coordinate:"); 
  scanf("%d%d", &x3,&y3);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
  glutInitWindowSize(500, 500); 
  glutInitWindowPosition(0,0); 
  glutCreateWindow("Scan Line - Burla Sai Teja");
  init();
  glutCreateMenu(menuDisplay);
  glutAddMenuEntry("Fill Shape", 1);
  glutAddMenuEntry("Outline Shape", 2);
  glutAddMenuEntry("Quit", 3); 
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDisplayFunc(display); 
  glutMainLoop();
}
