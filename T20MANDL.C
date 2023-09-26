/* Dyakonov Nickolay, ND4, 30.10.2020 */
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <time.h>
#include <math.h>

#include "COMPL.h"

#define FRAME_H 200
#define FRAME_W 200

unsigned char Frame[FRAME_H][FRAME_W][3];
int Zoom = 1;

void PutPixel( int x, int y, int r, int g, int b )
{
  if (x < 0 || y < 0 || x >= FRAME_W || y >= FRAME_H)
    return;
  Frame[y][x][0] = b;
  Frame[y][x][1] = g;
  Frame[y][x][2] = r;
}

int Mandelbrot( COMPL Z )
{
  COMPL Z0;
  int n = 0;
  Z0 = Z;

  while (n < 255 && (ComplNorm2(Z) < 4))
    Z = ComplAdd(ComplMul(Z, Z), Z0), n++;
  return n;
}

int Julia( COMPL Z, COMPL C )
{
  int n = 0;
  
  while (n++ < 255 && (ComplNorm2(Z) < 4))
    Z = ComplAdd(ComplMul(Z, Z), C);
  return n;
}

void DrawMandelbrot( void )
{
  DBL X0 = -2, X1 = 2, Y0 = -2, Y1 = 2;
  COMPL Z;
  int xs, ys, n;

  for (ys = 0; ys < FRAME_H; ys++)
    for (xs = 0; xs < FRAME_W; xs++)
    {
      Z = ComplSet(xs * (X1 - X0) /  FRAME_W + X0, ys * (Y1 - Y0) /  FRAME_H + Y0);
      n = Mandelbrot(Z);
      PutPixel(xs, ys, n, n / 8, n * 8);
    }
}

void DrawJulia( void )
{
  DBL X0 = -2, Xi = 2, Y0 = -2, Yi = 2;
  int ys, xs, n;
  COMPL Z, C;
  double SyncTime = clock() / (double)CLOCKS_PER_SEC;
  

  for (ys = 0; ys < FRAME_H; ys++)
    for (xs = 0; xs < FRAME_W; xs++)
    {
      C = ComplSet(sin(SyncTime + 1.1), cos(SyncTime + 3.3));
      Z = ComplSet(xs * (Xi - X0) / FRAME_W + X0, ys * (Yi - Y0) / FRAME_H + Y0);
      n = Julia(Z, C);
      PutPixel(xs, ys, n * sin(SyncTime) * n, n * 3 * n, n * 8);
    }
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
  else if (Key == '-')
    Zoom--;
  else if (Key == '+')
    Zoom++;
} 

void Display( void )
{
  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  DrawMandelbrot();
  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);
  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();

  glutSwapBuffers();
  glutPostRedisplay();
}

void main ( int ArgC, char *Argv[] )
{
  glutInit(&ArgC, Argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("PETROVICH");
  glutFullScreen();

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0.3, 0.47, 0.7, 1);
  glutMainLoop();
}               
