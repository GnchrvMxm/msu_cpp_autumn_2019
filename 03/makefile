CC=g++

all:
	$(CC) Linear_allocator.cpp -o Linear_allocator --std=c++11 -O2
	$(CC) malloc.cpp -o malloc --std=c++11 -O2
	
test: Linear_allocator test.py
	python3 test.py

run: Linear_allocator malloc
	./Linear_allocator
	#./malloc

clean:
	rm Linear_allocator malloc
