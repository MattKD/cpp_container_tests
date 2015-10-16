// Type for calling update functions for use in intrusiveListTest

#ifndef BAR_H
#define BAR_H

#include "util.h"
#include "update_funcs.h"

class Bar {
public:
  Bar() : prev{nullptr}, next{nullptr} { }
  virtual void update() { };

  void removeSelf()
  {
    prev->next = next;
    next->prev = prev;
    prev = next = nullptr;
  }

  void insertAfter(Bar *b)
  {
    prev = b;
    next = b->next;
    b->next = this;
    next->prev = this;
  }

  void addToSortedList(Bar *head, Bar *tail)
  {
    Bar *it = head->next;
    while (it != tail && it < this) {
      it = it->next;
    }

    it = it->prev;
    insertAfter(it);
  }

  Bar *prev, *next;
};

class Bar_A : public Bar {
public:
  Bar_A() : n{getRandomInt(0,10)}, k{0}, z{0} { }

  void update() override
  {
    updateA(n, k, z);
  }

private:
  int n;
  int k;
  int z;
};

class Bar_B : public Bar {
public:
  Bar_B() : x{0}, y{0} { }

  void update() override
  {
    updateB(x, y);
  }

private:
  int x;
  int y;
};

class Bar_C : public Bar {
public:
  Bar_C() : x{getRandomInt(0,10)}, y{getRandomInt(0,10)}, 
    w{getRandomInt(0,10)}, h{getRandomInt(0,10)} { }

  void update() override
  {
    updateC(x,w,w,h);
  }

private:
  int x,y,w,h;
};

class Bar_D : public Bar {
public:
  Bar_D() : n{1} { }

  void update() override
  {
    updateD(n);
  }

private:
  int n;
};


#endif
