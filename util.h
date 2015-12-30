#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <iostream>
#include <string>
#include <utility>

unsigned int getRandomInt();
int getRandomInt(int min, int max);

struct TimeResult {
  TimeResult(const std::vector<double> &times);

  double min, max, avg;
};

struct TestResult {
  TimeResult iterate, add, remove;
};

struct Test {
  std::string test_name;
  TestResult result;
};

typedef TestResult (*TestType)(int, int, bool, int);

template <class Func, class... Args>
Test runTest(const char *name, const Func &test, Args&&... args) 
{
  std::cout << "Running " << name << " test.\n";
  return { name, test(std::forward<Args>(args)...) }; 
}

template <class T>
static void getRandElems(const std::vector<T> &src, 
                         std::vector<T> &dest, int num)
{
  dest.clear();
  if (num > (int)src.size()) {
    num = src.size();
  }

  for (int i = 0; i < num; ++i) {
    while (true) {
      int r = getRandomInt(0, src.size() - 1);
      auto val = src[r];
      auto it = std::find(dest.begin(), dest.end(), val);
      if (it == dest.end()) {
        dest.push_back(std::move(val));
        break;
      }
    }
  }
}


#endif
