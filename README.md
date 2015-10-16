# vector_vs_list
Speed tests comparing a vector of pointers and intrusive list

This tests the time to iterate and add/remove elements in a vector/intrusive list. There are two vector tests: one normal vector of pointers to polymorphics objects, and another where the objects have an embedded index for quicker searching. All tests are also run sorted and unsorted.

Usage: vector_vs_list [-iters COUNT=1000] [-elems NUM=100000] [-add_rem NUM=100]

Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2015:
```
Number times each test is run: 1000
Number elements in vectors/lists: 100000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
Unsorted Vector of Pointers test: (11.61, 18.38, 13.61)
Sorted Vector of Pointers test: (11.15, 14.67, 11.59)
Unsorted Intrusive Vector of Pointers test: (11.29, 21.27, 13.21)
Sorted Intrusive Vector of Pointers test: (11.07, 14.06, 11.20)
Unsorted Intrusive List test: (11.16, 14.63, 12.55)
Sorted Intrusive List test: (11.07, 11.72, 11.17)

Add element times(min, max, average) in ms:
Unsorted Vector of Pointers test: (0.00, 0.00, 0.00)
Sorted Vector of Pointers test: (0.97, 2.84, 1.22)
Unsorted Intrusive Vector of Pointers test: (0.00, 0.00, 0.00)
Sorted Intrusive Vector of Pointers test: (6.09, 9.94, 7.72)
Unsorted Intrusive List test: (0.00, 0.00, 0.00)
Sorted Intrusive List test: (8.60, 13.00, 10.62)

Remove element times(min, max, average) in ms:
Unsorted Vector of Pointers test: (3.42, 6.85, 4.42)
Sorted Vector of Pointers test: (2.15, 4.60, 2.75)
Unsorted Intrusive Vector of Pointers test: (0.00, 0.06, 0.00)
Sorted Intrusive Vector of Pointers test: (12.01, 18.96, 15.28)
Unsorted Intrusive List test: (0.00, 0.02, 0.00)
Sorted Intrusive List test: (0.00, 0.01, 0.00)
```
