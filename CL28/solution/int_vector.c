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
        v->size > v->capacity) {
        return 0;
    }

    if (v->size < v->capacity) return 1;

    if (v->capacity > INT_MAX / 2) return 0;

    int new_capacity = v->capacity * 2;

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

/*
 * Insert value at the specified index.
 *
 * Shift elements to the right to make room.
 * Grow the vector if necessary.
 *
 * Returns 1 on success, 0 on failure.
 */
int insert(Vector* v, int index, int value) {
    if (v == NULL || v->data == NULL) return 0;

    // Valid indices: 0 through size (inclusive).
    if (index < 0 || index > v->size) return 0;

    // Grow the vector if needed.
    if (!ensure_room(v)) return 0;

    // Shift elements one position to the right.
    for (int i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }

    // Insert the new element.
    v->data[index] = value;

    // Update the size.
    v->size++;

    return 1;
}

/*
 * Remove the element at the specified index.
 *
 * Shift subsequent elements to the left.
 *
 * Returns 1 on success, 0 on failure.
 */
int remove_at(Vector* v, int index) {
    if (v == NULL || v->data == NULL) return 0;

    // Valid indices: 0 through size - 1.
    if (index < 0 || index >= v->size) return 0;

    // Shift elements one position to the left.
    for (int i = index; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }

    // Update the size.
    v->size--;

    return 1;
}

int pop(Vector* v, int* result) {
    if (v == NULL || v->data == NULL || result == NULL) return 0;

    if (v->size <= 0) return 0;

    *result = v->data[v->size - 1];
    v->size--;

    return 1;
}

/*
 * Return the number of elements currently stored.
 *
 * Returns -1 if v is NULL.
 */
int vector_size(const Vector* v) {
    if (v == NULL) return -1;

    return v->size;
}