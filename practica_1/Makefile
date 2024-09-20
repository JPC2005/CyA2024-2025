CXX= g++ 
CFLAGS= -std=c++17 -Wall
FLAGS= test
DEPS= $(FLAGS)_tools.h


.PHONY: all clean

all: compile 

%.0: %.cc $(DEPS)
	$(CXX) -c -o $@ $<

compile: $(FLAGS)_main.o $(FLAGS)_tools.o
	$(CXX) -o $(FLAGS) $^

clean:
	rm *.o
	rm $(FLAGS)
