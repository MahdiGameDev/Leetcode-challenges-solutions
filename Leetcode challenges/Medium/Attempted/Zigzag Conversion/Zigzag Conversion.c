#include <stdio.h>
#include <stdlib.h>


int str_len(char* string) {
    int len = 0;
    while (string[len] != '\0') len++;
    return len;
}

char* convert(char* s, int numRows) {
    int len = str_len(s);
    char* result = calloc(len + 1, sizeof(char));

    int constant = 2*(numRows - 1);
    int separation = constant;

    int amount = 0;
    int stop = 0;
    int index = 0;
    if (numRows == 1 || len <= numRows) return s;
    for (int pivot = 0; pivot < numRows; pivot++) {
        result[index++] = s[pivot];
        if (stop) {
            while ((pivot + separation) < len) {
                result[index++] = s[(pivot + separation)];
                separation += constant;
            }
        } else if (amount == 0) {
            while ((separation) < len) {
                result[index++] = s[separation];
                separation += constant;
            }
        } else {
            while ((pivot + separation - amount) < len) {
                result[index++] = s[pivot + separation - amount];
                if ((pivot + separation) < len) {
                    result[index++] = s[pivot + separation];
                }
                separation += constant;
            }
        }
        separation = constant;
        amount += 2;
        if (constant - amount == 0) {
            if (numRows > 3 || (numRows >= 3 && len == 4)) index--;
            stop = 1;
        }
    }
    result[index] = '\0';
    return result;
}

int main() {
    char* s = calloc(100, sizeof(char));
    printf("Enter a sequence of characters :\n");
    scanf("%s", s);
    printf("%s", convert(s, 4));
    return 0;
}