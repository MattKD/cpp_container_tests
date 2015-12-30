#include <chrono>
#include <algorithm>
#include <vector>
#include "bar.h"
#include "util.h"

static double 
iterateTest(Bar *head, Bar *tail)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Bar *b = head->next; b != tail; b = b->next) {
    b->update();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
removeTest(const std::vector<Bar*> &to_remove)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  for (Bar *b : to_remove) {
    b->removeSelf();
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

static double 
addTest(Bar *head, Bar *tail, const std::vector<Bar*> &to_add, bool sorted)
{
  namespace c = std::chrono;
  auto start = c::high_resolution_clock::now();

  if (sorted) {
    for (Bar *b : to_add) {
      b->addToSortedList(head, tail);
    }
  } else {
    for (Bar *b : to_add) {
      b->insertAfter(head);
    }
  }

  auto end = c::high_resolution_clock::now();
  auto d = c::duration<double, c::milliseconds::period>(end-start);
  return d.count();
}

TestResult intrusiveListTest(int iters, int num_elements, bool sorted, 
                             int num_add_remove)
{
  using std::vector;
  const int NUM_EACH_TYPE = num_elements / 4;
  const int NUM_BARS = NUM_EACH_TYPE * 4;

  vector<Bar_A> bar_a_pool(NUM_EACH_TYPE);
  vector<Bar_B> bar_b_pool(NUM_EACH_TYPE);
  vector<Bar_C> bar_c_pool(NUM_EACH_TYPE);
  vector<Bar_D> bar_d_pool(NUM_EACH_TYPE);
  vector<Bar*> bar_vec;
  bar_vec.reserve(num_elements);

  Bar head, tail;
  head.prev = nullptr;
  head.next = &tail;
  tail.prev = &head;
  tail.next = nullptr;

  for (int i = 0; i < NUM_EACH_TYPE; ++i) {
    bar_vec.push_back(&bar_a_pool[i]);
    bar_vec.push_back(&bar_b_pool[i]);
    bar_vec.push_back(&bar_c_pool[i]);
    bar_vec.push_back(&bar_d_pool[i]);
  }

  if (sorted) {
    std::sort(bar_vec.begin(), bar_vec.end());
  }

  for (int i = bar_vec.size()-1; i >= 0; --i) {
    bar_vec[i]->insertAfter(&head);
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Bar*> rand_bars;
  rand_bars.reserve(num_add_remove);

  for (int i = 0; i < iters; i++) {
    iterate_times[i] = iterateTest(&head, &tail);
    getRandElems(bar_vec, rand_bars, num_add_remove);
    remove_times[i] = removeTest(rand_bars);
    add_times[i] = addTest(&head, &tail, rand_bars, sorted);
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

