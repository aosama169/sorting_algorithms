#include <stdint.h>
#include "sort.h"
#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)
/**
 * sift_down - sift_down
 * @array: array containing heap
 * @sz: total size of array
 * @index: index of index node of heap
 * @nth: index of nth node in heap to examine
 */
void sift_down(int *array, size_t sz, size_t index, size_t nth)
{
size_t lrgst, left, right;
do {
left = getLeft(index);
right = getRight(index);
lrgst = index;
if (right <= nth && array[right] > array[index])
lrgst = right;
if (array[left] > array[lrgst])
lrgst = left;
if (index == lrgst)
return;
array[index] ^= array[lrgst];
array[lrgst] ^= array[index];
array[index] ^= array[lrgst];
print_array(array, sz);
index = lrgst;
} while (getLeft(index) <= nth);
}
/**
 * heap_sort - use heap sort array
 * @array: array to sorted
 * @sz: size of array
 */
void heap_sort(int *array, size_t sz)
{
size_t node, sorted;
if (array == NULL || sz < 2)
return;
for (node = getParent(sz - 1); node != SIZE_MAX; node--)
sift_down(array, sz, node, sz - 1);
for (sorted = sz - 1; sorted > 1; sorted--)
{
array[0] ^= array[sorted];
array[sorted] ^= array[0];
array[0] ^= array[sorted];
print_array(array, sz);
sift_down(array, sz, 0, sorted - 1);
}
array[0] ^= array[1];
array[1] ^= array[0];
array[0] ^= array[1];
print_array(array, sz);
}
