#include <chrono>
#include <algorithm>
#include <vector>
#include "foo.h"
#include "util.h"

static double 
iterateTest(std::vector<Foo*> &foo_ptrs)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : foo_ptrs) {
    f->update();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
removeTest(std::vector<Foo*> &foo_ptrs, std::vector<Foo*> &to_remove, 
           bool sorted)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  if (sorted) {
    for (Foo *f : to_remove) {
      auto iter = std::lower_bound(foo_ptrs.begin(), foo_ptrs.end(), f);
      foo_ptrs.erase(iter);
    }
  } else {
    for (Foo *f : to_remove) {
      auto iter = std::find(foo_ptrs.begin(), foo_ptrs.end(), f);
      *iter = foo_ptrs.back();
      foo_ptrs.pop_back();
    }
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
addTest(std::vector<Foo*> &foo_ptrs, std::vector<Foo*> &to_add, bool sorted)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  if (sorted) {
    for (Foo *f : to_add) {
      auto iter = std::lower_bound(foo_ptrs.begin(), foo_ptrs.end(), f);
      foo_ptrs.insert(iter, f);
    }
  } else {
    for (Foo *f : to_add) {
      foo_ptrs.push_back(f);
    }
  }
  to_add.clear();

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

TestResult 
vectorTest(int iters, int num_elements, bool sorted, int num_add_remove)
{
  using std::vector;

  const int NUM_EACH_TYPE = num_elements / 4;
  const int NUM_FOOS = NUM_EACH_TYPE * 4;

  vector<Foo_A> foo_a_pool(NUM_EACH_TYPE);
  vector<Foo_B> foo_b_pool(NUM_EACH_TYPE);
  vector<Foo_C> foo_c_pool(NUM_EACH_TYPE);
  vector<Foo_D> foo_d_pool(NUM_EACH_TYPE);
  vector<Foo*> foo_ptrs;
  foo_ptrs.reserve(NUM_FOOS);

  for (int i = 0; i < NUM_EACH_TYPE; ++i) {
    foo_ptrs.push_back(&foo_a_pool[i]);
    foo_ptrs.push_back(&foo_b_pool[i]);
    foo_ptrs.push_back(&foo_c_pool[i]);
    foo_ptrs.push_back(&foo_d_pool[i]);
  }

  if (sorted) {
    std::sort(foo_ptrs.begin(), foo_ptrs.end());
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Foo*> rand_foos;
  rand_foos.reserve(num_add_remove);

  for (int i = 0; i < iters; i++) {
    iterate_times[i] = iterateTest(foo_ptrs);
    getRandElems(foo_ptrs, rand_foos, num_add_remove);
    remove_times[i] = removeTest(foo_ptrs, rand_foos, sorted);
    add_times[i] = addTest(foo_ptrs, rand_foos, sorted);
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

