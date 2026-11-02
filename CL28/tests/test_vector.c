#include "../int_vector.h"
#include <stdio.h>
#include <string.h>

static int passed = 0, failed = 0;
#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "  FAIL at line %d: %s\n", __LINE__, #condition); \
        return 0; \
    } \
} while (0)

static int check_values(const Vector *v, const int *expected, int n) {
    CHECK(v->size == n);
    for (int i = 0; i < n; i++) CHECK(v->data[i] == expected[i]);
    return 1;
}

static int test_init_and_free(void) {
    Vector v;
    CHECK(init_vector(&v) == 1);
    CHECK(v.data != NULL && v.size == 0 && v.capacity == 4);
    free_vector(&v);
    CHECK(v.data == NULL && v.size == 0 && v.capacity == 0);
    CHECK(init_vector(NULL) == 0);
    free_vector(NULL);
    return 1;
}

static int test_append_and_growth(void) {
    Vector v;
    CHECK(init_vector(&v));
    for (int i = 0; i < 9; i++) CHECK(append(&v, i * 3));
    CHECK(v.size == 9 && v.capacity == 16);
    for (int i = 0; i < 9; i++) CHECK(v.data[i] == i * 3);
    CHECK(append(NULL, 5) == 0);
    free_vector(&v);
    return 1;
}

static int test_get_set(void) {
    Vector v;
    CHECK(init_vector(&v));
    CHECK(append(&v, 10) && append(&v, 20));
    int result = -77;
    CHECK(get(&v, 1, &result) == 1 && result == 20);
    CHECK(get(&v, -1, &result) == 0 && result == 20);
    CHECK(get(&v, 2, &result) == 0 && result == 20);
    CHECK(get(&v, 0, NULL) == 0);
    CHECK(get(NULL, 0, &result) == 0);
    CHECK(set(&v, 0, 99) == 1);
    CHECK(v.data[0] == 99 && v.size == 2);
    CHECK(set(&v, 2, 7) == 0 && set(&v, -1, 7) == 0);
    CHECK(set(NULL, 0, 7) == 0);
    free_vector(&v);
    return 1;
}

static int test_pop(void) {
    Vector v;
    CHECK(init_vector(&v));
    int out = -77;
    CHECK(pop(&v, &out) == 0 && out == -77);
    CHECK(append(&v, 11) && append(&v, 22));
    CHECK(pop(&v, &out) == 1 && out == 22 && v.size == 1);
    CHECK(pop(&v, NULL) == 0 && v.size == 1);
    CHECK(pop(NULL, &out) == 0);
    CHECK(pop(&v, &out) == 1 && out == 11 && v.size == 0);
    free_vector(&v);
    return 1;
}

static int test_insert_positions(void) {
    Vector v;
    CHECK(init_vector(&v));
    CHECK(insert(&v, 0, 20) == 1);
    CHECK(insert(&v, 0, 10) == 1);
    CHECK(insert(&v, 2, 40) == 1);
    CHECK(insert(&v, 2, 30) == 1);
    const int expected[] = {10, 20, 30, 40};
    CHECK(check_values(&v, expected, 4));
    free_vector(&v);
    return 1;
}

static int test_insert_growth(void) {
    Vector v;
    CHECK(init_vector(&v));
    for (int i = 0; i < 4; i++) CHECK(append(&v, i));
    CHECK(v.capacity == 4);
    CHECK(insert(&v, 2, 99) == 1);
    const int expected[] = {0, 1, 99, 2, 3};
    CHECK(check_values(&v, expected, 5));
    CHECK(v.capacity == 8);
    free_vector(&v);
    return 1;
}

static int test_insert_invalid(void) {
    Vector v;
    CHECK(init_vector(&v));
    CHECK(append(&v, 7));
    CHECK(insert(&v, -1, 9) == 0);
    CHECK(insert(&v, 2, 9) == 0);
    CHECK(insert(NULL, 0, 9) == 0);
    CHECK(v.size == 1 && v.data[0] == 7 && v.capacity == 4);
    free_vector(&v);
    return 1;
}

static int test_remove_positions(void) {
    Vector v;
    CHECK(init_vector(&v));
    for (int i = 1; i <= 4; i++) CHECK(append(&v, i * 10));
    CHECK(remove_at(&v, 1) == 1);
    const int a[] = {10, 30, 40};
    CHECK(check_values(&v, a, 3));
    CHECK(remove_at(&v, 0) == 1);
    CHECK(remove_at(&v, 1) == 1);
    CHECK(remove_at(&v, 0) == 1);
    CHECK(v.size == 0 && v.capacity == 4);
    free_vector(&v);
    return 1;
}

static int test_remove_invalid(void) {
    Vector v;
    CHECK(init_vector(&v));
    CHECK(remove_at(&v, 0) == 0);
    CHECK(append(&v, 42));
    CHECK(remove_at(&v, -1) == 0);
    CHECK(remove_at(&v, 1) == 0);
    CHECK(remove_at(NULL, 0) == 0);
    CHECK(v.size == 1 && v.data[0] == 42);
    free_vector(&v);
    return 1;
}

static int test_vector_size(void) {
    Vector v;
    CHECK(vector_size(NULL) == -1);
    CHECK(init_vector(&v));
    CHECK(vector_size(&v) == 0);
    CHECK(append(&v, 10) && append(&v, 20));
    CHECK(vector_size(&v) == 2);
    CHECK(pop(&v, &(int){0}));
    CHECK(vector_size(&v) == 1);
    free_vector(&v);
    return 1;
}

typedef int (*TestFn)(void);
static void run(const char *name, TestFn fn) {
    printf("%-28s", name);
    if (fn()) { puts("PASS"); passed++; }
    else { puts("FAIL"); failed++; }
}

int main(int argc, char **argv) {
    const int todo = argc > 1 && strcmp(argv[1], "todo") == 0;
    const int all = argc > 1 && strcmp(argv[1], "all") == 0;
    if (argc > 2 || (argc == 2 && !todo && !all)) {
        fprintf(stderr, "Usage: %s [provided|todo|all]\n", argv[0]);
        return 2;
    }
    if (!todo) {
        puts("Provided-function tests:");
        run("init_vector / free_vector", test_init_and_free);
        run("append / capacity growth", test_append_and_growth);
        run("get / set", test_get_set);
        run("pop", test_pop);
    }
    if (todo || all) {
        puts("Student-implementation tests:");
        run("insert: positions", test_insert_positions);
        run("insert: capacity growth", test_insert_growth);
        run("insert: invalid indices", test_insert_invalid);
        run("remove_at: positions", test_remove_positions);
        run("remove_at: invalid indices", test_remove_invalid);
        run("vector_size", test_vector_size);
    }
    printf("\n%d passed, %d failed\n", passed, failed);
    return failed ? 1 : 0;
}
