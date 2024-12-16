#include <stdio.h>
#include <stdlib.h>


int* combine_array(int* nums1, int nums1Size, int* nums2, int nums2Size) { // Combine to arrays of integers
    int size = nums1Size + nums2Size;
    int* result = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        if (i < nums1Size) {
            result[i] = nums1[i];
        } else {
            result[i] = nums2[i - nums1Size];
        }
    }
    return result;
}

void sort_array(int* array, int size) { // Bubble Sort (the lowest one, the more perform the sort algorithm will be the more time you win)
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (array[j] < array[j - 1]) {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size; // Calcul the size
    int* array = combine_array(nums1, nums1Size, nums2, nums2Size); // Combine the arrays
    sort_array(array, size); // Sort the combined array
    double median; // Hold the median
    median = (size % 2 == 0) ? (array[size/2 - 1] + array[size/2 - 1 + 1]) / 2.0 : array[size/2];
    return median;
}

