CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g

.PHONY: all test test-todo test-all clean
all: demo tests/test_vector

demo: main.c int_vector.c int_vector.h
	$(CC) $(CFLAGS) main.c int_vector.c -o $@

tests/test_vector: tests/test_vector.c int_vector.c int_vector.h
	$(CC) $(CFLAGS) tests/test_vector.c int_vector.c -o $@

test: tests/test_vector
	./tests/test_vector

test-todo: tests/test_vector
	./tests/test_vector todo

test-all: tests/test_vector
	./tests/test_vector all

clean:
	rm -f demo tests/test_vector *.o
