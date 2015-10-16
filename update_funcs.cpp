#include "util.h"

void updateA(int &n, int &k, int &z)
{
  if (n == getRandomInt(0,10)) {
    ++k;
  } else {
    --k;
  }
  if (k > 1000 || k < -1000) {
    if (z == 0) {
      z = 1;
    } else {
      z += k / z;
    }
    k = 0;
  }
}
 
void updateB(int &x, int &y)
{
  x += getRandomInt(-10,10);
  y += getRandomInt(-10,10);
}

void updateC(int &x, int &y, int &w, int &h)
{
  int x2 = getRandomInt(0,1000); 
  int y2 = getRandomInt(0,1000); 
  int w2 = getRandomInt(0,1000); 
  int h2 = getRandomInt(0,1000); 

  if (x+w < x2 || x > x2+w2 || y+h < y2 || y > y2+h2) {
    return;
  }

  x = x2 - w;
  y += y2;
}

void updateD(int &n)
{
  int f = getRandomInt(200, 201);
  int c = 1;
  for (int a = 1, b = 1, i = 3; i <= f; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  n = c;
}



