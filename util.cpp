#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include "util.h"

TimeResult::TimeResult(const std::vector<double> &times)
{
  min = *std::min_element(times.begin(), times.end());
  max = *std::max_element(times.begin(), times.end());
  double total = std::accumulate(times.begin(), times.end(), 0.0);
  avg = total / (double) times.size();
}

std::mt19937& getRandomGen()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return gen;
}

unsigned int getRandomInt()
{
  auto &g = getRandomGen();
  return g();
}

int getRandomInt(int min, int max)
{
  std::uniform_int_distribution<> dis(min, max);
  return dis(getRandomGen());
}
