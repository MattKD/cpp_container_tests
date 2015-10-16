#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <iostream>
#include <string>

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

inline
Test runTest(const char *name, TestType test, int iters, int elems, 
             bool sorted, int add_remove)
{
  std::cout << "Running " << name << " test.\n";
  return { name, test(iters, elems, sorted, add_remove) }; 
}

#endif
