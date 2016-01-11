# cpp_container_tests
Usage: cpp_container_tests [-iters COUNT=1000] [-elems NUM=100000] [-add_rem NUM=100]

Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2013:
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
Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2013 (500000 elems):
```
Number times each test is run: 1000
Number elements in vectors/lists: 500000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (54.00, 83.00, 61.60)
vector (sorted) test: (54.00, 65.00, 55.10)
vector (sorted,batched) test: (54.00, 65.00, 55.07)
intrusive vector test: (55.00, 81.00, 61.52)
intrusive vector (sorted) test: (54.00, 81.00, 55.29)
intrusive list test: (55.00, 78.00, 59.84)
intrusive list (sorted) test: (54.00, 61.00, 54.99)
set test: (69.00, 90.01, 75.28)
unordered_set test: (69.00, 87.00, 75.45)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (11.00, 22.00, 13.55)
vector (sorted,batched) test: (15.00, 22.00, 16.51)
intrusive vector test: (0.00, 1.00, 0.00)
intrusive vector (sorted) test: (104.01, 169.01, 128.80)
intrusive list test: (0.00, 1.00, 0.00)
intrusive list (sorted) test: (59.00, 88.01, 75.19)
set test: (0.00, 1.00, 0.06)
unordered_set test: (0.00, 1.00, 0.05)

Remove element times(min, max, average) in ms:
vector test: (16.00, 28.00, 21.21)
vector (sorted) test: (11.00, 24.00, 13.61)
vector (sorted,batched) test: (0.00, 1.00, 0.04)
intrusive vector test: (0.00, 1.00, 0.01)
intrusive vector (sorted) test: (104.01, 159.01, 127.02)
intrusive list test: (0.00, 1.00, 0.02)
intrusive list (sorted) test: (0.00, 1.00, 0.01)
set test: (0.00, 1.00, 0.13)
unordered_set test: (0.00, 1.00, 0.15)
```
Results on Windows 7/Intel i7-4770K compiled with Visual Studio 2013:
```
Number times each test is run: 1000
Number elements in vectors/lists: 100000
Number elements to add/remove in a frame: 100

Running vector test.
Running vector (sorted) test.
Running vector (sorted,batched) test.
Running intrusive vector test.
Running intrusive vector (sorted) test.
Running intrusive list test.
Running intrusive list (sorted) test.
Running set test.
Running unordered_set test.

Iteration times(min, max, average) in ms:
vector test: (0.00, 10.00, 6.02)
vector (sorted) test: (0.00, 10.00, 5.35)
vector (sorted,batched) test: (0.00, 10.00, 5.39)
intrusive vector test: (0.00, 10.00, 6.07)
intrusive vector (sorted) test: (0.00, 10.00, 5.38)
intrusive list test: (0.00, 10.00, 6.04)
intrusive list (sorted) test: (0.00, 10.00, 5.44)
set test: (0.00, 10.00, 6.46)
unordered_set test: (0.00, 10.00, 6.40)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (0.00, 10.00, 1.51)
vector (sorted,batched) test: (0.00, 10.00, 1.38)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (0.00, 10.00, 4.72)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 10.00, 6.10)
set test: (0.00, 0.00, 0.00)
unordered_set test: (0.00, 0.00, 0.00)

Remove element times(min, max, average) in ms:
vector test: (0.00, 10.00, 1.34)
vector (sorted) test: (0.00, 10.00, 0.56)
vector (sorted,batched) test: (0.00, 0.00, 0.00)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (0.00, 10.00, 8.66)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 0.00, 0.00)
set test: (0.00, 10.00, 0.03)
unordered_set test: (0.00, 10.00, 0.06)
```
Results on Windows 7/Intel i7-4770K compiled with Visual Studio 2013 (500000 elems):
```
Number times each test is run: 1000
Number elements in vectors/lists: 500000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (20.00, 40.00, 29.30)
vector (sorted) test: (20.00, 30.00, 26.94)
vector (sorted,batched) test: (20.00, 30.00, 26.81)
intrusive vector test: (20.00, 40.00, 29.07)
intrusive vector (sorted) test: (20.00, 30.00, 26.82)
intrusive list test: (20.00, 40.00, 28.75)
intrusive list (sorted) test: (20.00, 30.00, 26.77)
set test: (30.00, 50.00, 43.01)
unordered_set test: (30.00, 50.00, 42.85)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (0.00, 10.00, 7.31)
vector (sorted,batched) test: (0.00, 10.00, 7.66)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (20.00, 40.00, 30.25)
intrusive list test: (0.00, 10.00, 0.01)
intrusive list (sorted) test: (20.00, 40.00, 34.34)
set test: (0.00, 10.00, 0.03)
unordered_set test: (0.00, 10.00, 0.01)

Remove element times(min, max, average) in ms:
vector test: (0.00, 10.00, 6.84)
vector (sorted) test: (0.00, 10.00, 3.63)
vector (sorted,batched) test: (0.00, 10.00, 0.01)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (40.00, 60.00, 48.24)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 10.00, 0.01)
set test: (0.00, 10.00, 0.08)
unordered_set test: (0.00, 10.00, 0.05)
```
