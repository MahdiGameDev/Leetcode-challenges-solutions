#include <stdlib.h>
#include <stdio.h>

int str_len(char* string) {
    int len = 0;
    while (string[len] != '\0') len++;
    return len;
}

void str_rev(char* string) {
    int len = str_len(string);
    for (int i = 0; i < len/2; i++) {
        char tmp = string[i];
        string[i] = string[len - 1 - i];
        string[len - 1 - i] = tmp; 
    }
}

void str_cpy(char* destination, char* source) {
    int len = str_len(source);
    int i;
    for (i = 0; i < len; i++) destination[i] = source[i];
    destination[i] = '\0';
}

void str_cat(char* destination, char* source) {
    int from = str_len(destination);
    int to = from + str_len(source);
    int i = from;
    for (i = from; i < to; i++) {
        destination[i] = source[i - from];
    }
    destination[i] = '\0';
}

int* RomanCode(int* values, int size, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    int index = 0;
    int base = 1;
    for (int i = 0; i < size; i++) {
        if (i != 0) base *= 10;
        if (base > 1000) base = 1000;
        int val = values[i]/base;
        if (val < 4) for(int i = 0; i <= (val - 1); i++) result[index++] = (1*base);
        else if (val == 4) result[index++] = (4*base);
        else if (val < 9) {
            for (int i = 0; i < (val - 5); i++) result[index++] = (1*base);
            result[index++] = (5*base);
        }
        else if (val == 9) result[index++] = (9*base);
    }
    (*returnSize) = index;
    return result;
}

char* valueToRoman(int value) {
    char* result = malloc(100 * sizeof(char));
    if (value == 1) str_cpy(result, "I");
    else if (value == 4) str_cpy(result, "VI");
    else if (value == 5) str_cpy(result, "V");
    else if (value == 9) str_cpy(result, "XI");
    else if (value == 10) str_cpy(result, "X");
    else if (value == 40) str_cpy(result, "LX");
    else if (value == 50) str_cpy(result, "L");
    else if (value == 90) str_cpy(result, "CX");
    else if (value == 100) str_cpy(result, "C");
    else if (value == 400) str_cpy(result, "DC");
    else if (value == 500) str_cpy(result, "D");
    else if (value == 900) str_cpy(result, "MC");
    else if (value == 1000) str_cpy(result, "M");
    return result;
}

char* intToRoman(int num) {
    int* separation = calloc(100, sizeof(int));
    int index = 0;
    int base = 1;
    while (num > 0) {
        separation[index++] = (num % 10)*base;
        base *= 10;
        num /= 10;
    }
    int size;
    int* romanCode = RomanCode(separation, index, &size);
    char* result = calloc(100, sizeof(char));
    for (int i = 0; i < size; i++) {
        str_cat(result, valueToRoman(romanCode[i]));
    }
    str_rev(result);
    printf("result : %s\n", result);
    return result;
}
