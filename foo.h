// Type for calling update functions for use in ptrVectorTest

#ifndef FOO_H
#define FOO_H

#include "util.h"
#include "update_funcs.h"

class Foo {
public:
  virtual void update() = 0;
};

class Foo_A : public Foo {
public:
  Foo_A() : n{getRandomInt(0,10)}, k{0}, z{0} { }

  void update() override
  {
    updateA(n, k, z);
  }

private:
  int n;
  int k;
  int z;
};

class Foo_B : public Foo {
public:
  Foo_B() : x{0}, y{0} { }

  void update() override
  {
    updateB(x, y);
  }

private:
  int x;
  int y;
};

class Foo_C : public Foo {
public:
  Foo_C() : x{getRandomInt(0,10)}, y{getRandomInt(0,10)}, 
    w{getRandomInt(0,10)}, h{getRandomInt(0,10)} { }

  void update() override
  {
    updateC(x,w,w,h);
  }

private:
  int x,y,w,h;
};

class Foo_D : public Foo {
public:
  Foo_D() : n{1} { }

  void update() override
  {
    updateD(n);
  }

private:
  int n;
};


#endif
