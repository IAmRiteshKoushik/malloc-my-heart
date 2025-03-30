# Writing Your Own Memory Allocator

The `malloc` contains the following:
0. Basic allocator
1. Malloc (beginning)
2. Chunk allocation
3. Unique value
4. Free
5. Hashtable Beginnings
6. Fixed Hashtable
7. Separate Data Structure

## Notes on Allocator

Think of the following as memory partitions
```
---------------------------------
| * | * |   | * | * | * |
---------------------------------
```
If we consider each block to be 1 byte and I have to insert something
worth of 2 bytes then I cannot use the `unallocated` space in the centre
I have to allocated chunks towards the end.
