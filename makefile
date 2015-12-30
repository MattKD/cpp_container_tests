CC = g++
CFLAGS = -Wall -pedantic -std=c++14 -O2

ODIR = build
_OBJ = container_tests.o intrusive_list_test.o intrusive_vector_test.o \
			 set_test.o unordered_set_test.o update_funcs.o util.o vector_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

container_tests: $(ODIR) $(OBJ) 
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(ODIR):
	mkdir $@

$(ODIR)/container_tests.o: container_tests.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/intrusive_list_test.o: intrusive_list_test.cpp bar.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/intrusive_vector_test.o: intrusive_vector_test.cpp baz.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/set_test.o: set_test.cpp foo.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/unordered_set_test.o: unordered_set_test.cpp foo.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/update_funcs.o: update_funcs.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/util.o: util.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/vector_test.o: vector_test.cpp foo.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

bar.h: update_funcs.h util.h

baz.h: update_funcs.h util.h

foo.h: update_funcs.h util.h
