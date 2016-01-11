# cpp_container_tests
Usage: container_tests [-iters COUNT=1000] [-elems NUM=100000] [-add_rem NUM=100]

Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2015:
```
Number times each test is run: 1000
Number elements in vectors/lists: 100000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (11.00, 22.00, 12.53)
vector (sorted) test: (10.00, 17.00, 11.05)
vector (sorted,batched) test: (10.00, 35.00, 11.52)
intrusive vector test: (11.00, 27.00, 13.35)
intrusive vector (sorted) test: (10.00, 18.00, 11.03)
intrusive list test: (11.00, 28.00, 13.07)
intrusive list (sorted) test: (10.00, 13.00, 10.98)
set test: (13.00, 24.00, 15.06)
unordered_set test: (13.00, 20.00, 14.99)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (2.00, 5.00, 2.64)
vector (sorted,batched) test: (2.00, 11.00, 3.12)
intrusive vector test: (0.00, 1.00, 0.00)
intrusive vector (sorted) test: (8.00, 15.00, 9.20)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (8.00, 13.00, 10.11)
set test: (0.00, 1.00, 0.04)
unordered_set test: (0.00, 1.00, 0.05)

Remove element times(min, max, average) in ms:
vector test: (3.00, 9.00, 4.23)
vector (sorted) test: (2.00, 5.00, 2.70)
vector (sorted,batched) test: (0.00, 1.00, 0.03)
intrusive vector test: (0.00, 1.00, 0.00)
intrusive vector (sorted) test: (12.00, 30.00, 15.40)
intrusive list test: (0.00, 1.00, 0.01)
intrusive list (sorted) test: (0.00, 1.00, 0.00)
set test: (0.00, 1.00, 0.10)
unordered_set test: (0.00, 1.00, 0.06)
```
