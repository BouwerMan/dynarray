/**
 * Dynamic Array Library. Header only library providing basic dynamic array functionality
 * Copyright (C) 2024  Dylan Parks
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/** USAGE INFORMATION:
 * Make your own struct that should look something like:
 * typedef struct {
 *     int* items;
 *     size_t count;
 *     size_t capacity;
 * } int_da;
 * Where items is a pointer to any type
 */

#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#define DA_REALLOC realloc
#define DA_FREE free
#define DA_ASSERT assert

#include <assert.h>
#include <stdlib.h>

#define DA_INIT_CAP 64
#define DA_EXPECTED_SIZE (sizeof(void*) + (sizeof(size_t) * 2))

#define array_len(array) (sizeof(array) / sizeof(array[0]))

#define da_append(da_p, item)                                                                                          \
    do {                                                                                                               \
        if ((da_p)->count >= (da_p)->capacity) {                                                                       \
            (da_p)->capacity = (da_p)->capacity == 0 ? DA_INIT_CAP : (da_p)->capacity * 2;                             \
            (da_p)->items = DA_REALLOC((da_p)->items, (da_p)->capacity * sizeof(*(da_p)->items));                      \
            DA_ASSERT((da_p)->items != NULL && "Out of memory");                                                       \
        }                                                                                                              \
        (da_p)->items[(da_p)->count++] = (item);                                                                       \
    } while (0)

#define da_free(da_p) DA_FREE((da_p)->items)

#define da_shrink(da_p)                                                                                                \
    do {                                                                                                               \
        if ((da_p)->count < ((da_p)->capacity)) {                                                                      \
            (da_p)->capacity = (da_p)->count;                                                                          \
            (da_p)->items = DA_REALLOC((da_p)->items, (da_p)->capacity * sizeof(*(da_p)->items));                      \
            DA_ASSERT((da_p)->items != NULL && "Failed to shrink");                                                    \
        }                                                                                                              \
    } while (0)

#define da_at(da_p, index) (DA_ASSERT(index >= 0), DA_ASSERT(index < (da_p)->count), (da_p)->items[index])

#endif // INCLUDE_DA_DYNARRAY_H_
