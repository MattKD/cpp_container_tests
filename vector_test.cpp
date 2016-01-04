#include <chrono>
#include <algorithm>
#include <vector>
#include <cassert>
#include "foo.h"
#include "util.h"

static double 
iterateTest(std::vector<Foo*> &foo_ptrs)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (auto f : foo_ptrs) {
    f->update();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
batchedIterateTest(std::vector<std::pair<Foo*,bool>> &foo_ptrs)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (auto f : foo_ptrs) {
    f.first->update();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

// Sets each Foo*'s bool to false, so it will be removed when batch adding 
static double 
batchedRemoveTest(std::vector<std::pair<Foo*,bool>> &foo_ptrs, 
                const std::vector<Foo*> &to_remove)
{
  auto compare = [](std::pair<Foo*,bool> f1, Foo *f2) { 
    return f1.first < f2; };
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_remove) {
    auto iter = std::lower_bound(foo_ptrs.begin(), foo_ptrs.end(), 
                                 f, compare);
    iter->second = false;
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
sortedRemoveTest(std::vector<Foo*> &foo_ptrs, const std::vector<Foo*> &to_remove)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_remove) {
    auto iter = std::lower_bound(foo_ptrs.begin(), foo_ptrs.end(), f);
    foo_ptrs.erase(iter);
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
removeTest(std::vector<Foo*> &foo_ptrs, const std::vector<Foo*> &to_remove)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_remove) {
    auto iter = std::find(foo_ptrs.begin(), foo_ptrs.end(), f); 
    *iter = foo_ptrs.back();
    foo_ptrs.pop_back();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
sortedAddTest(std::vector<Foo*> &foo_ptrs, const std::vector<Foo*> &to_add)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_add) {
    auto iter = std::lower_bound(foo_ptrs.begin(), foo_ptrs.end(), f);
    foo_ptrs.insert(iter, f);
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

// Adds all Foo* to end of vector then does one sort, which also places 
// Foo* with false flag to end and removes all at once.
static double 
batchedAddTest(std::vector<std::pair<Foo*,bool>> &foo_ptrs, 
               const std::vector<Foo*> &to_add)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_add) {
    foo_ptrs.push_back(std::make_pair(f, true));
  }
  auto compare = [](std::pair<Foo*,bool> f1, std::pair<Foo*,bool> f2) { 
    if (f1.second == false) {
      return false;
    } else if (f2.second == false) {
      return true; 
    } else {
      return f1.first < f2.first; 
    }
  };
  std::sort(foo_ptrs.begin(), foo_ptrs.end(), compare);

  while (foo_ptrs.back().second == false) {
    foo_ptrs.pop_back();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
addTest(std::vector<Foo*> &foo_ptrs, const std::vector<Foo*> &to_add)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_add) {
    foo_ptrs.push_back(f);
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

TestResult 
vectorTest(int iters, int num_elements, bool sorted, int num_add_remove,
           bool batched)
{
  using std::vector;
  using std::pair;
  using std::make_pair;

  const int NUM_EACH_TYPE = num_elements / 4;
  const int NUM_FOOS = NUM_EACH_TYPE * 4;

  vector<Foo_A> foo_a_pool(NUM_EACH_TYPE);
  vector<Foo_B> foo_b_pool(NUM_EACH_TYPE);
  vector<Foo_C> foo_c_pool(NUM_EACH_TYPE);
  vector<Foo_D> foo_d_pool(NUM_EACH_TYPE);
  vector<Foo*> foo_ptrs;
  // For batched tests, each Foo* has a bool to tell if it should be removed
  vector<pair<Foo*,bool>> foo_ptrs2; 
  foo_ptrs.reserve(NUM_FOOS);
  foo_ptrs2.reserve(NUM_FOOS+num_add_remove);

  for (int i = 0; i < NUM_EACH_TYPE; ++i) {
    foo_ptrs.push_back(&foo_a_pool[i]);
    foo_ptrs.push_back(&foo_b_pool[i]);
    foo_ptrs.push_back(&foo_c_pool[i]);
    foo_ptrs.push_back(&foo_d_pool[i]);
  }

  if (sorted) {
    std::sort(foo_ptrs.begin(), foo_ptrs.end());
  }

  for (auto f : foo_ptrs) {
    foo_ptrs2.push_back(make_pair(f, true));
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Foo*> rand_foos;
  rand_foos.reserve(num_add_remove);

  if (sorted) {
    if (batched) {
      for (int i = 0; i < iters; i++) {
        iterate_times[i] = batchedIterateTest(foo_ptrs2);
        getRandElems(foo_ptrs, rand_foos, num_add_remove);
        remove_times[i] = batchedRemoveTest(foo_ptrs2, rand_foos);
        add_times[i] = batchedAddTest(foo_ptrs2, rand_foos);
      }
    } else {
      for (int i = 0; i < iters; i++) {
        iterate_times[i] = iterateTest(foo_ptrs);
        getRandElems(foo_ptrs, rand_foos, num_add_remove);
        remove_times[i] = sortedRemoveTest(foo_ptrs, rand_foos);
        add_times[i] = sortedAddTest(foo_ptrs, rand_foos);
      }
    }
  } else {
    for (int i = 0; i < iters; i++) {
      iterate_times[i] = iterateTest(foo_ptrs);
      getRandElems(foo_ptrs, rand_foos, num_add_remove);
      remove_times[i] = removeTest(foo_ptrs, rand_foos);
      add_times[i] = addTest(foo_ptrs, rand_foos);
    }
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

