#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

// Setting the maximum cap of our heap to be 640_000
#define HEAP_CAP 640000
// Setting the maximum cap on the number of objects we can hold to 1024
#define HEAP_ALLOCED_CAP 1024

typedef struct {
    void *start;
    size_t size;
} Heap_Chunk;

char heap[HEAP_CAP] = {0};
size_t heap_size = 0;

// This keeps track of the pointer and the size of each chunk of memory that
// is going to be allocated in the heap. Therefore, it points to different
// chunks on the "heap"
Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP];
size_t heap_alloced_size = 0;

void *heap_alloc(size_t size) {
    assert(heap_size + size <= HEAP_CAP);
    void *result = heap + heap_size;
    heap_size += size;

    const Heap_Chunk chunk = {
        .start = result,
        .size = size,
    };
    assert(heap_alloced_size < HEAP_ALLOCED_CAP);
    heap_alloced[heap_alloced_size++] = chunk;

    return result;
}

void heap_dump_alloced_chunks(void){
    printf("Allocated Chunks (%zu):\n", heap_alloced_size);
    for(size_t i = 0; i < heap_alloced_size; ++i){
        printf("Start: %p, size: %zu\n",
            heap_alloced[i].start,
            heap_alloced[i].size
        );
    }
}

/*
* There are 3 possible situations that can happen when you try to deallocate
* memory:
* 1. Correct pointer is provided (MEMORY FREE)
* 2. Invalid within allocated memory partition of the heap
* 3. Invalid outside of allocated memory partition of the heap
*
* NOTE: "allocated memory partition" means the parts of the heap[] which are
* holding some kind of data as opposed to being empty
*/
void heap_free(void *ptr) {
    (void) ptr;
    assert(false && "TODO: heap_free is not implemented");
}

/*
 * Outside of trying to scan the heap, the heap_collect() function may try
 * and scan the stack as well.
 */
void heap_collect() {
    assert(false && "TODO: heap_collect is not implemented");
}

int main() {
    char *root = heap_alloc(69);
    for(int i = 0; i < 26; i++){
        root[i] = i + 'A'; // Generates A, B, C, D, ...
    }

    heap_free(root);
    return 0;
}
