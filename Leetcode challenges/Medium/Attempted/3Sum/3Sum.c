#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** array2D(int size, int columnSizes) {
    int** array = malloc(sizeof(int*) * size);
    if (array == NULL) return NULL;  // Check for malloc failure

    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(int) * columnSizes);
        if (array[i] == NULL) {
            // Free already allocated memory in case of failure
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

int checkList(int** list, int* targetLine, int size, int nbrline) {
    int attempts = 0;
    for (int i = 0; i < nbrline; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (targetLine[k] == list[i][j]) attempts++;
            }
        }
        if (attempts >= size) {
            printf("yes\n");
            return 1;
        } else attempts = 0;
    }
    printf("no\n");
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = array2D(numsSize, 3);
    *returnColumnSizes = malloc(sizeof(int) * numsSize);
    int rowIndex = 0;
    bool canAddZero = true;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    int tmp[3] = {nums[i], nums[j], nums[k]};
                    if (!checkList(result, tmp, 3, rowIndex)) {
                        result[rowIndex][0] = nums[i];
                        result[rowIndex][1] = nums[j];
                        result[rowIndex][2] = nums[k];
                        (*returnColumnSizes)[rowIndex] = 3;
                        rowIndex++;
                    } else if (nums[i] == 0 && nums[j] == 0 && nums[k] == 0 && canAddZero) {
                        canAddZero = false;
                        result[rowIndex][0] = nums[i];
                        result[rowIndex][1] = nums[j];
                        result[rowIndex][2] = nums[k];
                        (*returnColumnSizes)[rowIndex] = 3;
                        rowIndex++;
                    } 
                }
            }
        }
    }

    *returnSize = rowIndex;
    return result;
}