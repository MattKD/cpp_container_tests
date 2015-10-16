CC = g++
CFLAGS = -Wall -pedantic -std=c++14 -O2

ODIR = obj
_OBJ = vector_vs_list_test.o util.o update_funcs.o ptr_vector_test.o \
			 intrusive_ptr_vector_test.o intrusive_list_test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

vector_vs_list: $(ODIR) $(OBJ) 
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(ODIR):
	mkdir $@

$(ODIR)/vector_vs_list_test.o: vector_vs_list_test.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/util.o: util.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/update_funcs.o: update_funcs.cpp util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/ptr_vector_test.o: ptr_vector_test.cpp foo.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/intrusive_ptr_vector_test.o: intrusive_ptr_vector_test.cpp baz.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(ODIR)/intrusive_list_test.o: intrusive_list_test.cpp bar.h util.h
	$(CC) -o $@ -c $< $(CFLAGS)
