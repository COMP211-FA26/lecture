#ifndef INT_VECTOR_H
#define INT_VECTOR_H

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

/* Provided implementations. Functions returning int report 1 on success
   and 0 on failure unless documented otherwise. */
int init_vector(Vector* v);
int append(Vector* v, int value);
int get(const Vector* v, int index, int* result);
int set(Vector* v, int index, int value);
int pop(Vector* v, int* result);
void free_vector(Vector* v);

/* TODO: insert
   Insert value at index, shifting existing elements at index and beyond
   one position to the right. Valid indices are 0 through v->size,
   inclusive (inserting at v->size appends).
   Grow capacity when needed, using the same doubling strategy as append.
   Return 1 on success, 0 for an invalid index, invalid vector, or
   allocation failure. On failure, leave the vector unchanged. */
int insert(Vector* v, int index, int value);

/* TODO: remove_at
   Remove the element at index and shift later elements one position left.
   Decrease size by one; capacity does not need to shrink.
   Valid indices are 0 through v->size - 1.
   Return 1 on success, 0 for an invalid index or invalid vector.
   On failure, leave the vector unchanged. */
int remove_at(Vector* v, int index);

/* TODO: vector_size
   Return the number of elements currently stored (not the capacity).
   Return -1 if v is NULL. */
int vector_size(const Vector* v);

#endif
