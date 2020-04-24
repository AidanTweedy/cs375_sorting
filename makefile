
all: quicksort.o
	g++ -g -Wall -Werror -std=c++14 quicksort.o -o quicksort

quicksort.o: quicksort.cpp
	g++ -c -g -Wall -Werror -std=c++14 quicksort.cpp -o quicksort.o

.PHONY: clean all

clean:
	rm -rf quicksort *.o

run: all
	./quicksort