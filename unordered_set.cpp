#include <chrono>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "foo.h"
#include "util.h"

static double 
iterateTest(std::unordered_set<Foo*> &foo_ptrs)
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
removeTest(std::unordered_set<Foo*> &foo_ptrs, const std::vector<Foo*> &to_remove)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_remove) {
    foo_ptrs.erase(f);
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
addTest(std::unordered_set<Foo*> &foo_set, const std::vector<Foo*> &to_add)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Foo *f : to_add) {
    foo_set.insert(f);
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

TestResult 
unordered_setTest(int iters, int num_elements, int num_add_remove)
{
  using std::vector;
  using std::unordered_set;

  const int NUM_EACH_TYPE = num_elements / 4;
  const int NUM_FOOS = NUM_EACH_TYPE * 4;

  vector<Foo_A> foo_a_pool(NUM_EACH_TYPE);
  vector<Foo_B> foo_b_pool(NUM_EACH_TYPE);
  vector<Foo_C> foo_c_pool(NUM_EACH_TYPE);
  vector<Foo_D> foo_d_pool(NUM_EACH_TYPE);
  vector<Foo*> foo_vec;
  unordered_set<Foo*> foo_set;
  foo_vec.reserve(NUM_FOOS);

  for (int i = 0; i < NUM_EACH_TYPE; ++i) {
    foo_vec.push_back(&foo_a_pool[i]);
    foo_vec.push_back(&foo_b_pool[i]);
    foo_vec.push_back(&foo_c_pool[i]);
    foo_vec.push_back(&foo_d_pool[i]);
  }
  for (Foo *f : foo_vec) {
    foo_set.insert(f);
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Foo*> rand_foos;
  rand_foos.reserve(num_add_remove);

  for (int i = 0; i < iters; i++) {
    iterate_times[i] = iterateTest(foo_set);
    getRandElems(foo_vec, rand_foos, num_add_remove);
    remove_times[i] = removeTest(foo_set, rand_foos);
    add_times[i] = addTest(foo_set, rand_foos);
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

