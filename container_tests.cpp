#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "util.h"

TestResult vectorTest(int iters, int num_elements, bool sorted, 
                      int num_add_remove);
TestResult intrusiveVectorTest(int iters, int num_elements, bool sorted, 
                               int num_add_remove);
TestResult intrusiveListTest(int iters, int num_elements, bool sorted, 
                             int num_add_remove);
TestResult setTest(int iters, int num_elements, int num_add_remove);
TestResult unordered_setTest(int iters, int num_elements, int num_add_remove);

void printUsage();
int strToInt(const char*);

int main(int argc, char *argv[])
{
  using std::cout;

  int NUM_ITERS = 1000;
  int NUM_ELEMENTS = 100000;
  int NUM_ADD_REMOVE = 100;

  try {
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-iters") == 0 && i+1 < argc) {
        NUM_ITERS = strToInt(argv[++i]);
      } else if (strcmp(argv[i], "-elems") == 0 && i+1 < argc) {
        NUM_ELEMENTS = strToInt(argv[++i]);
      } else if (strcmp(argv[i], "-add_rem") == 0 && i+1 < argc) {
        NUM_ADD_REMOVE = strToInt(argv[++i]);
      } else {
        cout << "Error: Invalid option '" << argv[i] << "'\n";
        printUsage();
        return EXIT_FAILURE;
      } 
    }
  } catch (std::exception &e) {
    cout << e.what() << "\n";    
    printUsage();
    return EXIT_FAILURE;
  }
  if (NUM_ITERS < 0 || NUM_ELEMENTS < 0 || NUM_ADD_REMOVE < 0) {
    cout << "Options -iters, -elems, and -add_rem must all be greater than 0\n";
    printUsage();
    return EXIT_FAILURE;
  }
 
  cout << "Number times each test is run: " << NUM_ITERS << "\n";
  cout << "Number elements in vectors/lists: " << NUM_ELEMENTS << "\n";
  cout << "Number elements to add/remove in a frame: " << NUM_ADD_REMOVE 
        << "\n\n";

  Test tests[] = { 
    runTest("vector", vectorTest, 
            NUM_ITERS, NUM_ELEMENTS, false, NUM_ADD_REMOVE),
    runTest("vector (sorted)", vectorTest,
            NUM_ITERS, NUM_ELEMENTS, true, NUM_ADD_REMOVE),
    runTest("intrusive vector", 
            intrusiveVectorTest, NUM_ITERS, NUM_ELEMENTS, 
            false, NUM_ADD_REMOVE),
    runTest("intrusive vector (sorted)", 
            intrusiveVectorTest, NUM_ITERS, NUM_ELEMENTS, 
            true, NUM_ADD_REMOVE),
    runTest("intrusive list", intrusiveListTest, 
            NUM_ITERS, NUM_ELEMENTS, false, NUM_ADD_REMOVE),
    runTest("intrusive list (sorted)", intrusiveListTest, 
            NUM_ITERS, NUM_ELEMENTS, true, NUM_ADD_REMOVE),
    runTest("set", setTest, NUM_ITERS, NUM_ELEMENTS, NUM_ADD_REMOVE),
    runTest("unordered_set", setTest, NUM_ITERS, NUM_ELEMENTS, NUM_ADD_REMOVE)
  };

  cout << std::setprecision(2) << std::fixed;
  cout << "\nIteration times(min, max, average) in ms: \n";
  for (auto &test : tests) {
    cout << test.test_name << " test: ("
         << test.result.iterate.min << ", "
         << test.result.iterate.max << ", "
         << test.result.iterate.avg << ")\n";
  }

  cout << "\nAdd element times(min, max, average) in ms: \n";
  for (auto &test : tests) {
    cout << test.test_name << " test: ("
         << test.result.add.min << ", "
         << test.result.add.max << ", "
         << test.result.add.avg << ")\n";
  }

  cout << "\nRemove element times(min, max, average) in ms: \n";
  for (auto &test : tests) {
    cout << test.test_name << " test: ("
         << test.result.remove.min << ", "
         << test.result.remove.max << ", "
         << test.result.remove.avg << ")\n";
  }


  return 0; 
}

void printUsage()
{
  std::cout << "Usage: vector_vs_list_test [-iters COUNT] "
               "[-elems NUM] [-add_rem NUM]\n"
               "\tDefaults: -iters 1000 -elems 100000 -add_rem 100\n"; 
}

int strToInt(const char *str)
{
  char *str_end = nullptr; // for detecting errors in strtol
  int n = strtol(str, &str_end, 10);
  if (errno == ERANGE){
    errno = 0;
    throw std::runtime_error("Error: Number entered is too large.");
  }
  if (str == str_end) {
    throw std::runtime_error("Error converting string to int");
  }
  return n;
}
 
