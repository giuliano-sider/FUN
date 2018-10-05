SHELL := /bin/bash

PROGS = progs
TESTDIR = tests
LIBS = libs

CC = gcc
CPP = g++

CLEAR_SOME_SPACE = echo -e '\n\n\n\n\n\n\n\n\n\n\n\n'

INCLUDES = -I ./include

CFLAGS = -Wall $(INCLUDES)
CPPFLAGS = -Wall -std=c++11 $(INCLUDES)


# O3 mode turned off by default. define O3 or O3DEBUG in the make invocation to change this option.
ifdef O3DEBUG
  CFLAGS += -DO3DEBUG -g -O3
  CPPFLAGS += -DO3DEBUG -g -O3
else 
  ifdef O3
    CFLAGS += -O3
    CPPFLAGS += -O3
  else
    CFLAGS += -DDEBUG -g
    CPPFLAGS += -DDEBUG -g
  endif
endif


################################################################################
# utility executables and tests
	

EXECS = $(PROGS)/find_matches

TESTS = $(TESTDIR)/test_find_matches.sh

################################################################################
# generic rules

.PHONY: all
all: $(EXECS) $(TESTS)

.PHONY: test
test: $(TESTS)
	@for i in $(TESTS); do $(CLEAR_SOME_SPACE) && echo "running $$i" && ./$$i; done

.PHONY: clean
clean:
	rm -f $(EXECS) \
	      *.o \
	      */*.o


%.o: %.c
	@$(CLEAR_SOME_SPACE)
	$(CC) $(CFLAGS) -c  $< -o $@

%.o: %.cpp
	@$(CLEAR_SOME_SPACE)
	$(CPP) $(CPPFLAGS) -c  $< -o $@


################################################################################
# build for the executables


$(PROGS)/find_matches: $(PROGS)/find_matches.cpp $(LIBS)/string_matching.o
	@$(CLEAR_SOME_SPACE)
	$(CPP) $(CPPFLAGS) $^ -o $@

################################################################################