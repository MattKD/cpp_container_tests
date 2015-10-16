#include <chrono>
#include <algorithm>
#include <vector>
#include "bar.h"
#include "util.h"

static void getRandBars(Bar *head, int list_size, 
                        std::vector<Bar*> &dest, int num)
{
  std::vector<int> indexes;
  indexes.reserve(num);

  for (int i = 0; i < num; ++i) {
    std::vector<int>::iterator it;
    int idx;

    do {
      idx = getRandomInt(0, list_size - 1);
      it = std::find(indexes.begin(), indexes.end(), idx);
    } while (it != indexes.end());

    indexes.push_back(idx);
  }

  std::sort(indexes.begin(), indexes.end());

  Bar *b = head->next;
  int last_idx = 0;

  for (int next_idx : indexes) {
    int advance = next_idx - last_idx;
    for (int i = 0; i < advance; ++i) {
      b = b->next;
    }
    dest.push_back(b);
    last_idx = next_idx;
  }
}

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
removeTest(std::vector<Bar*> &to_remove)
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
addTest(Bar *head, Bar *tail, std::vector<Bar*> &to_add, bool sorted)
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
  to_add.clear();

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

  Bar head, tail;
  head.prev = nullptr;
  head.next = &tail;
  tail.prev = &head;
  tail.next = nullptr;

  if (sorted) {
    for (int i = NUM_EACH_TYPE - 1; i >= 0; --i) {
      bar_d_pool[i].addToSortedList(&head, &tail);
    }
    for (int i = NUM_EACH_TYPE - 1; i >= 0; --i) {
      bar_c_pool[i].addToSortedList(&head, &tail);
    }
    for (int i = NUM_EACH_TYPE - 1; i >= 0; --i) {
      bar_b_pool[i].addToSortedList(&head, &tail);
    }
    for (int i = NUM_EACH_TYPE - 1; i >= 0; --i) {
      bar_a_pool[i].addToSortedList(&head, &tail);
    }
  } else {
    for (int i = 0; i < NUM_EACH_TYPE; ++i) {
      bar_a_pool[i].insertAfter(&head);
      bar_b_pool[i].insertAfter(&head);
      bar_c_pool[i].insertAfter(&head);
      bar_d_pool[i].insertAfter(&head);
    }
  }

  vector<double> iterate_times(iters);
  vector<double> add_times(iters);
  vector<double> remove_times(iters);

  vector<Bar*> rand_bars;
  rand_bars.reserve(num_add_remove);

  for (int i = 0; i < iters; i++) {
    iterate_times[i] = iterateTest(&head, &tail);
    getRandBars(&head, NUM_BARS, rand_bars, num_add_remove);
    remove_times[i] = removeTest(rand_bars);
    add_times[i] = addTest(&head, &tail, rand_bars, sorted);
  }

  TestResult result = { TimeResult(iterate_times), 
                        TimeResult(add_times),
                        TimeResult(remove_times) };

  return result;
}

