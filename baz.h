// Type for calling update functions for use in intrusiveVectorTest

#ifndef BAZ_H
#define BAZ_H

#include "util.h"
#include "update_funcs.h"

class Baz {
public:
  Baz() : lookup_index{-1} { }
  virtual void update() = 0;
  int lookup_index;
};

class Baz_A : public Baz {
public:
  Baz_A() : n{getRandomInt(0,10)}, k{0}, z{0} { }

  void update() override
  {
    updateA(n, k, z);
  }

private:
  int n;
  int k;
  int z;
};

class Baz_B : public Baz {
public:
  Baz_B() : x{0}, y{0} { }

  void update() override
  {
    updateB(x, y);
  }

private:
  int x;
  int y;
};

class Baz_C : public Baz {
public:
  Baz_C() : x{getRandomInt(0,10)}, y{getRandomInt(0,10)}, 
    w{getRandomInt(0,10)}, h{getRandomInt(0,10)} { }

  void update() override
  {
    updateC(x,w,w,h);
  }

private:
  int x,y,w,h;
};

class Baz_D : public Baz {
public:
  Baz_D() : n{1} { }

  void update() override
  {
    updateD(n);
  }

private:
  int n;
};


#endif

