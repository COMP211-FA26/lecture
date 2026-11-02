#include "int_vector.h"
#include <stdio.h>

int main(void) {
    Vector v;
    if (!init_vector(&v)) {
        fprintf(stderr, "Could not initialize vector\n");
        return 1;
    }

    for (int i = 1; i <= 5; i++) {
        if (!append(&v, i * 10)) {
            free_vector(&v);
            return 1;
        }
    }

    printf("Vector contents: ");
    for (int i = 0; i < v.size; i++) {
        int value;
        if (!get(&v, i, &value)) {
            free_vector(&v);
            return 1;
        }
        printf("%d%s", value, i + 1 == v.size ? "\n" : " ");
    }

    /* Try insert(), remove_at(), and vector_size() after implementing them. */
    free_vector(&v);
    return 0;
}
