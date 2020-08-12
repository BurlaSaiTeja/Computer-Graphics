#include<GL/glut.h> 
#include<stdio.h> 
#include<math.h>

typedef GLfloat point[2];
int flag = 0, speed = 0, start=1; 
float flagSpeed = 0;

void binCoeff(int n, int * C) 
{ 
  int k, j;
  for (k = 0; k <= n; k++) 
  { 
    C[k] = 1;
    for (j = n; j >= (n - k) + 1; j--) 
      C[k] *= j;
    for (j = k; j >= 2; j--) 
      C[k] /= j;
  }
}

void computeBezPt(float u, point bezCurvePt, int numControlPoints, point * controlPoints, int * C) 
{
  int k;
  float bezBlendFn; 
  bezCurvePt[0] = 0;
  bezCurvePt[1] = 0;
  int n = numControlPoints - 1;
  for (k = 0; k < numControlPoints; k++) 
  { 
    bezBlendFn = C[k] * pow(u, k) * pow(1 - u, n - k);
    bezCurvePt[0] += controlPoints[k][0] * bezBlendFn; 
    bezCurvePt[1] += controlPoints[k][1] * bezBlendFn;
  }
}

void bezier(point * controlPoints, int numControlPoints, int nBezierPoints)
{ 
  point bezCurvePt;
  float u; 
  int * C, k;
  C = new int[numControlPoints]; 
  binCoeff(numControlPoints - 1, C); 
  glBegin(GL_LINE_STRIP);
  for (k = 0; k < nBezierPoints; k++) 
  {
    u = (float) k / (float) nBezierPoints;
    computeBezPt(u, bezCurvePt, numControlPoints, controlPoints, C); 
    glVertex2fv(bezCurvePt);
  }
  glEnd(); 
  delete[] C;
}

void draw(point * controlPoints, int numControlPoints, int nBezierPoints)
{ 
  for (int i = 0; i < 8; i++) 
  {
    glTranslatef(0, -0.8, 0);
    bezier(controlPoints, numControlPoints, nBezierPoints);
  }
}

void display() 
{
  int numControlPoints = 4; 
  int nBezierPoints = 20;
  point controlPoints[] = {{20, 100}, {30, 110}, {50, 90}, {60, 100}};
  static float theta = 0;
  double PI_rad = (22.0 / 7.0) / 180.0; 
  glClear(GL_COLOR_BUFFER_BIT); 
  controlPoints[1][0] += 10 * sin(theta * PI_rad); 
  controlPoints[1][1] += 5 * sin(theta * PI_rad); 
  controlPoints[2][0] -= 10 * sin((theta + 30) * PI_rad); 
  controlPoints[2][1] -= 10 * sin((theta + 30) * PI_rad); 
  controlPoints[3][0] -= 4 * sin((theta) * PI_rad); 
  controlPoints[3][1] += sin((theta - 30) * PI_rad);
  if(start == 1)
  {
    if(speed == -1)
    {
      flagSpeed -= 0.1;
      if(flagSpeed < 0.1)
        flagSpeed = 0;
    }
    else if(speed == 1) 
      flagSpeed += 0.1;
    speed = 0;
    theta += 0.1 + flagSpeed;
  }
  if (theta > 360) 
    theta -= 360; 
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0, 0.0, 0.0); 
  glPushMatrix();
  glLineWidth(5); 
  if(flag==0)
  {
    glColor3f(255 / 255, 153 / 255.0, 51 / 255.0); //Indian flag: Orange color code
    draw(controlPoints, numControlPoints, nBezierPoints); 
    glColor3f(1, 1, 1); //Indian flag: white color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(19 / 255.0, 136 / 255.0, 8 / 255.0); //Indian flag: green color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
  }
  else if(flag == 1)
  {
    glColor3f(67 / 255.0, 176 / 255.0, 42 / 255.0); //Sierra Leone flag: Greencolor code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(1,1,1); // Sierra Leone flag: White color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(105/255.0, 179/255.0, 231/255.0); // Sierra Leone flag: Blue color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
  }
  else if(flag == 2)
  {
    glColor3f(234 / 255.0, 40 / 255.0, 57 / 255.0); //Maritious flag: Red color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(26/255.0, 32/255.0, 109/255.0); //Maritious flag: Blue color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(255/255.0, 213 / 255.0, 0 / 255.0); //Maritious flag: Yellow color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
    glColor3f(0/255.0, 165 / 255.0, 81 / 255.0); //Maritious flag: Green color code 
    draw(controlPoints, numControlPoints, nBezierPoints);
  }
  glPopMatrix(); 
  glColor3f(0.7, 0.5, 0.3); 
  glLineWidth(5); 
  glBegin(GL_LINES); 
  glVertex2f(20, 100);
  glVertex2f(20, 40); 
  glEnd();
  glFlush(); 
  glutSwapBuffers(); 
  glutPostRedisplay();
}

void menuDisplay(int ch)
{ 
  switch(ch)
  {
    case 1: flag = 0;
            break;
    case 2: flag = 1;
            break;
    case 3: flag = 2;
            break;
    case 4: start = (start + 1)%2; 
            break;
    case 5: speed = 1; 
            break;
    case 6: speed = -1; 
            break;
    case 7: exit(0);
  }
  display();
}

void myinit() 
{ 
  glMatrixMode(GL_PROJECTION); 
  gluOrtho2D(0, 130, 0, 130);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv) 
{ 
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 
  glutInitWindowSize(600, 600); 
  glutCreateWindow("Bezier Curve – Burla Sai Teja"); 
  myinit();
  glutCreateMenu(menuDisplay); 
  glutAddMenuEntry("India Flag", 1); 
  glutAddMenuEntry("Sierra Leone Flag", 2); 
  glutAddMenuEntry("Mauritius Flag", 3);
  glutAddMenuEntry("Start/Stop Animation", 4); 
  glutAddMenuEntry("Increase Flag Speed", 5); 
  glutAddMenuEntry("Decrease Flag Speed", 6); 
  glutAddMenuEntry("Quit", 7); 
  glutAttachMenu(GLUT_RIGHT_BUTTON); 
  glutDisplayFunc(display);
  glutMainLoop();
}
