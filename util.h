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

#endif
