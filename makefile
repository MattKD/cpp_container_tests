CC := g++
CFLAGS := -Wall -pedantic -std=c++14 -O2

SRCS := container_tests.cpp intrusive_list_test.cpp intrusive_vector_test.cpp \
			set_test.cpp unordered_set_test.cpp update_funcs.cpp util.cpp \
			vector_test.cpp

DEPDIR := deps
DEPS := $(patsubst %,$(DEPDIR)/%.makefile,$(SRCS))
ODIR := build
OBJS := $(patsubst %.cpp,$(ODIR)/%.o,$(SRCS))

container_tests: $(OBJS) 
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(DEPDIR):
	mkdir $@

$(ODIR):
	mkdir $@

$(DEPDIR)/%.cpp.makefile: %.cpp | $(DEPDIR)
	$(CC) $(CFLAGS) -MM $< -MT $(ODIR)/$*.o > $@

-include $(DEPS)

$(ODIR)/%.o: | $(DEPDIR)/%.cpp.makefile $(ODIR)
	$(CC) -o $@ -c $*.cpp $(CFLAGS)
		
.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
