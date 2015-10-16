# vector_vs_list
Speed tests comparing a vector of pointers and intrusive list

This tests the time to iterate and add/remove elements in a vector/intrusive list. There are two vector tests: one normal vector of pointers to polymorphics objects, and another where the objects have an embedded index for quicker searching. All tests are also run sorted and unsorted.

Usage: vector_vs_list [-iters COUNT=1000] [-elems NUM=100000] [-add_rem NUM=100]

