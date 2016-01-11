# cpp_container_tests
Usage: cpp_container_tests [-iters COUNT=1000] [-elems NUM=100000] [-add_rem NUM=100]

Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2013:
```
Number times each test is run: 1000
Number elements in vectors/lists: 100000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (11.00, 21.00, 13.20)
vector (sorted) test: (10.00, 17.00, 11.16)
vector (sorted,batched) test: (10.00, 17.00, 11.16)
intrusive vector test: (11.00, 15.00, 12.97)
intrusive vector (sorted) test: (10.00, 16.00, 11.20)
intrusive list test: (11.00, 16.00, 12.86)
intrusive list (sorted) test: (10.00, 16.00, 11.20)
set test: (13.00, 18.00, 15.47)
unordered_set test: (13.00, 22.00, 15.62)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (2.00, 5.00, 2.69)
vector (sorted,batched) test: (0.00, 1.00, 0.55)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (8.00, 14.00, 10.16)
intrusive list test: (0.00, 1.00, 0.00)
intrusive list (sorted) test: (8.00, 15.00, 10.04)
set test: (0.00, 1.00, 0.04)
unordered_set test: (0.00, 1.00, 0.05)

Remove element times(min, max, average) in ms:
vector test: (3.00, 6.00, 4.29)
vector (sorted) test: (2.00, 5.00, 2.69)
vector (sorted,batched) test: (0.00, 1.00, 0.03)
intrusive vector test: (0.00, 1.00, 0.00)
intrusive vector (sorted) test: (14.00, 22.00, 16.99)
intrusive list test: (0.00, 1.00, 0.01)
intrusive list (sorted) test: (0.00, 1.00, 0.00)
set test: (0.00, 1.00, 0.09)
unordered_set test: (0.00, 1.00, 0.10)
```
Results on Windows 7/Intel i3-2370M compiled with Visual Studio 2013 (500000 elems):
```
Number times each test is run: 1000
Number elements in vectors/lists: 500000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (55.00, 81.00, 62.22)
vector (sorted) test: (54.00, 86.00, 55.60)
vector (sorted,batched) test: (54.00, 83.00, 54.95)
intrusive vector test: (54.00, 71.00, 60.98)
intrusive vector (sorted) test: (54.00, 76.00, 55.41)
intrusive list test: (54.00, 72.00, 60.00)
intrusive list (sorted) test: (54.00, 73.00, 55.27)
set test: (69.00, 84.00, 75.34)
unordered_set test: (69.00, 82.00, 74.73)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (11.00, 24.00, 13.73)
vector (sorted,batched) test: (3.00, 5.00, 3.18)
intrusive vector test: (0.00, 1.00, 0.00)
intrusive vector (sorted) test: (101.01, 170.01, 128.50)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (59.00, 92.01, 75.31)
set test: (0.00, 1.00, 0.04)
unordered_set test: (0.00, 1.00, 0.06)

Remove element times(min, max, average) in ms:
vector test: (16.00, 31.00, 21.24)
vector (sorted) test: (11.00, 25.00, 13.77)
vector (sorted,batched) test: (0.00, 1.00, 0.05)
intrusive vector test: (0.00, 1.00, 0.01)
intrusive vector (sorted) test: (101.01, 164.01, 126.84)
intrusive list test: (0.00, 1.00, 0.02)
intrusive list (sorted) test: (0.00, 1.00, 0.02)
set test: (0.00, 1.00, 0.14)
unordered_set test: (0.00, 1.00, 0.15)
```
Results on Windows 7/Intel i7-4770K compiled with Visual Studio 2013:
```
Number times each test is run: 1000
Number elements in vectors/lists: 100000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (0.00, 10.00, 6.28)
vector (sorted) test: (0.00, 10.00, 5.33)
vector (sorted,batched) test: (0.00, 10.00, 5.33)
intrusive vector test: (0.00, 10.00, 6.08)
intrusive vector (sorted) test: (0.00, 10.00, 5.19)
intrusive list test: (0.00, 10.00, 6.04)
intrusive list (sorted) test: (0.00, 10.00, 5.35)
set test: (0.00, 10.00, 6.46)
unordered_set test: (0.00, 10.00, 6.39)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (0.00, 10.00, 1.55)
vector (sorted,batched) test: (0.00, 10.00, 0.39)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (0.00, 10.00, 5.63)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 20.00, 5.96)
set test: (0.00, 10.00, 0.01)
unordered_set test: (0.00, 10.00, 0.01)

Remove element times(min, max, average) in ms:
vector test: (0.00, 10.00, 1.32)
vector (sorted) test: (0.00, 10.00, 0.64)
vector (sorted,batched) test: (0.00, 10.00, 0.01)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (0.00, 20.00, 10.36)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 0.00, 0.00)
set test: (0.00, 10.00, 0.02)
unordered_set test: (0.00, 10.00, 0.02)

```
Results on Windows 7/Intel i7-4770K compiled with Visual Studio 2013 (500000 elems):
```
Number times each test is run: 1000
Number elements in vectors/lists: 500000
Number elements to add/remove in a frame: 100

Iteration times(min, max, average) in ms:
vector test: (20.00, 40.00, 29.13)
vector (sorted) test: (20.00, 30.00, 26.60)
vector (sorted,batched) test: (20.00, 30.00, 26.73)
intrusive vector test: (20.00, 40.00, 28.79)
intrusive vector (sorted) test: (20.00, 30.00, 26.53)
intrusive list test: (20.00, 30.00, 28.30)
intrusive list (sorted) test: (20.00, 30.00, 26.71)
set test: (30.00, 50.00, 42.70)
unordered_set test: (30.00, 50.00, 42.69)

Add element times(min, max, average) in ms:
vector test: (0.00, 0.00, 0.00)
vector (sorted) test: (0.00, 10.00, 7.37)
vector (sorted,batched) test: (0.00, 10.00, 1.68)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (20.00, 40.00, 29.93)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (20.00, 50.00, 36.37)
set test: (0.00, 10.00, 0.01)
unordered_set test: (0.00, 10.00, 0.02)

Remove element times(min, max, average) in ms:
vector test: (0.00, 10.00, 6.55)
vector (sorted) test: (0.00, 10.00, 3.48)
vector (sorted,batched) test: (0.00, 10.00, 0.03)
intrusive vector test: (0.00, 0.00, 0.00)
intrusive vector (sorted) test: (40.00, 60.00, 47.85)
intrusive list test: (0.00, 0.00, 0.00)
intrusive list (sorted) test: (0.00, 0.00, 0.00)
set test: (0.00, 10.00, 0.11)
unordered_set test: (0.00, 10.00, 0.12)
```
