#include "int_vector.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

int init_vector(Vector* v) {
    if (v == NULL) return 0;
    int* data = malloc(INITIAL_CAPACITY * sizeof(int));
    if (data == NULL) return 0;
    v->data = data;
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    return 1;
}

void free_vector(Vector* v) {
    if (v == NULL) return;
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

static int ensure_room(Vector* v) {
    if (v == NULL || v->data == NULL || v->size < 0 || v->capacity <= 0 ||
        v->size > v->capacity)
        return 0;

    if (v->size < v->capacity) return 1;

    // INT_MAX is the largest value an int can hold. Since capacity is an int,
    // make sure doubling it won't cause integer overflow.
    if (v->capacity > INT_MAX / 2) return 0;

    int new_capacity = v->capacity * 2;

    // SIZE_MAX is the largest value a size_t can hold. Make sure the number
    // of bytes we want to allocate won't overflow when multiplying by
    // sizeof(int).
    if ((size_t)new_capacity > SIZE_MAX / sizeof(int)) return 0;

    int* new_data = realloc(v->data, (size_t)new_capacity * sizeof(int));

    if (new_data == NULL) return 0;

    v->data = new_data;
    v->capacity = new_capacity;

    return 1;
}
int append(Vector* v, int value) {
    if (!ensure_room(v)) return 0;
    v->data[v->size] = value;
    v->size++;
    return 1;
}

int get(const Vector* v, int index, int* result) {
    if (v == NULL || v->data == NULL || result == NULL) return 0;
    if (index < 0 || index >= v->size) return 0;
    *result = v->data[index];
    return 1;
}

int set(Vector* v, int index, int value) {
    if (v == NULL || v->data == NULL) return 0;
    if (index < 0 || index >= v->size) return 0;
    v->data[index] = value;
    return 1;
}

int insert(Vector* v, int index, int value) {
    /* TODO: Implement as specified in int_vector.h.
       Hint: ensure_room(v) grows the allocation when necessary. */
    (void)v;
    (void)index;
    (void)value;
    return 0;
}

int remove_at(Vector* v, int index) {
    /* TODO: Implement as specified in int_vector.h. */
    (void)v;
    (void)index;
    return 0;
}

int pop(Vector* v, int* result) {
    if (v == NULL || v->data == NULL || result == NULL) return 0;
    if (v->size <= 0) return 0;
    *result = v->data[v->size - 1];
    v->size--;
    return 1;
}

int vector_size(const Vector* v) {
    /* TODO: Implement as specified in int_vector.h. */
    (void)v;
    return -1;
}
