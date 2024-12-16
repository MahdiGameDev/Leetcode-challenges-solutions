#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = calloc(2, sizeof(int)); // Create an array of size 2
                result[0] = i;
                result[1] = j;
                (*returnSize) = 2;
                return result;
            }
        }
    }

    // If no solution found
    (*returnSize) = 0;
    return NULL; // Return Null
}

int main() {
    int size;

    // Size input
    printf("Enter the size :\n");
    scanf("%d", &size);

    // Nums input
    printf("Enter the numbers :\n");
    int* nums = calloc(size, sizeof(int)); // Create an array with dynamic memoty allocate with a size
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    // Target number input
    int target;
    printf("Enter the target number :\n");
    scanf("%d", &target);

    // Search for the result
    int returnSize;
    int* result = twoSum(nums, size, target, &returnSize);
    if (returnSize) {
        printf("\n[");
        for (int i = 0; i < returnSize; i++) {
            if (i == 0) printf("%d", result[i]);
            else {
                printf(", %d", result[i]);
            }
        }
        printf("]\n");
    } else {
        printf("\nNo result found :(\n");
    }

    return 0;
}