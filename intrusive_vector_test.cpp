#include <chrono>
#include <algorithm>
#include <vector>
#include "baz.h"
#include "util.h"

static void getRandBazs(const std::vector<Baz*> &src, 
                        std::vector<Baz*> &dest, int num)
{
  for (int i = 0; i < num; ++i) {
    Baz *f;
    std::vector<Baz*>::iterator it;

    do {
      int r = getRandomInt(0, src.size() - 1);
      f = src[r];
      it = std::find(dest.begin(), dest.end(), f);
    } while (it != dest.end());

    dest.push_back(f);
  }
}

static double 
iterateTest(std::vector<Baz*> &baz_ptrs)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Baz *f : baz_ptrs) {
    f->update();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
removeTest(std::vector<Baz*> &baz_ptrs, std::vector<Baz*> &to_remove, 
           bool sorted)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  if (sorted) {
    for (Baz *f : to_remove) {
      for (int i = f->lookup_index, end = (int)baz_ptrs.size() - 1; i < end; ++i) {
        baz_ptrs[i] = baz_ptrs[i+1];
        baz_ptrs[i]->lookup_index = i;
      }
      baz_ptrs.pop_back();
      f->lookup_index = -1;
    }
  } else {
    for (Baz *f : to_remove) {
      baz_ptrs[f->lookup_index] = baz_ptrs.back();
      baz_ptrs.pop_back();
      f->lookup_index = -1;
    }
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
addTest(std::vector<Baz*> &baz_ptrs, std::vector<Baz*> &to_add, bool sorted)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  if (sorted) {
    for (Baz *f : to_add) {
      auto iter = std::lower_bound(baz_ptrs.begin(), baz_ptrs.end(), f);
      iter = baz_ptrs.insert(iter, f);
      int iter_idx = iter - baz_ptrs.begin();
      for (auto end_iter = baz_ptrs.end(); iter != end_iter; ++iter) {
        (*iter)->lookup_index = iter_idx;
        ++iter_idx;
      }
    }
  } else {
    for (Baz *f : to_add) {
      baz_ptrs.push_back(f);
      f->lookup_index = baz_ptrs.size() - 1;
    }
  }

  to_add.clear();

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

TestResult 
intrusiveVectorTest(int iters, int num_elements, bool sorted, 
                       int num_add_remove)
{
  using std::vector;

  const int NUM_EACH_TYPE = num_elements / 4;
  const int NUM_FOOS = NUM_EACH_TYPE * 4;

  vector<Baz_A> baz_a_pool(NUM_EACH_TYPE);
  vector<Baz_B> baz_b_pool(NUM_EACH_TYPE);
  vector<Baz_C> baz_c_pool(NUM_EACH_TYPE);
  vector<Baz_D> baz_d_pool(NUM_EACH_TYPE);
  vector<Baz*> baz_ptrs;
  baz_ptrs.reserve(NUM_FOOS);

  for (int i = 0; i < NUM_EACH_TYPE; ++i) {
    baz_ptrs.push_back(&baz_a_pool[i]);
    baz_ptrs.push_back(&baz_b_pool[i]);
    baz_ptrs.push_back(&baz_c_pool[i]);
    baz_ptrs.push_back(&baz_d_pool[i]);
  }

  for (int i = 0, end = baz_ptrs.size(); i < end; ++i) {
    baz_ptrs[i]->lookup_index = i;
  }

  if (sorted) {
    std::sort(baz_ptrs.begin(), baz_ptrs.end());
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Baz*> rand_bazs;
  rand_bazs.reserve(num_add_remove);

  for (int i = 0; i < iters; i++) {
    iterate_times[i] = iterateTest(baz_ptrs);
    getRandBazs(baz_ptrs, rand_bazs, num_add_remove);
    remove_times[i] = removeTest(baz_ptrs, rand_bazs, sorted);
    add_times[i] = addTest(baz_ptrs, rand_bazs, sorted);
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

