#define __GNU_SOURCE
#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    size_t count;
    size_t capacity;
} int_da;

int main(void)
{
    int_da da = { 0 };
    da_append(&da, 69420);

    for (size_t i = 0; i < DA_INIT_CAP * 3 - 13; i++) {
        da_append(&da, i);
    }

    for (size_t i = 0; i < da.count; i++) {
        printf("%d ", da.items[i]);
    }
    puts("");
    printf("size: %zu\n", sizeof(da));
    printf("expected: %zu\n", DA_EXPECTED_SIZE);

    int at = da_at(&da, 13);
    printf("%d, %d\n", at, da.items[13]);

    printf("count: %zu\n", da.count);
    printf("before shrink: %zu\n", da.capacity);
    da_shrink(&da);
    printf("after shrink: %zu\n", da.capacity);

    da_free(&da);

    return EXIT_SUCCESS;
}
