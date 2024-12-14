#include <stdio.h>

int str_len(char* string) { // Calcul the lenght of a string
    int len = 0;
    while (string[len] != '\0') len++;
    return len;
}

void str_rev(char* string) { // reverse a string
    int len = str_len(string);
    for (int i = 0; i < len/2; i++) {
        char tmp = string[i];
        string[i] = string[len - 1 - i];
        string[len - 1 - i] = tmp;
    }
}

void str_clean(char* string) { // Clear the blankes
    while(string[0] == ' ') {
        str_rev(string);
        string[str_len(string) - 1] = '\0';
        str_rev(string);
    }
}

long myAtoi(char* string) {
    // Clean the string
    str_clean(string);

    // Check if negative and remove the sign
    long result = 0;
    int is_negative = 0;
    char digit;
    if (string[0] == '-') {
        is_negative = 1;
        str_rev(string);
        string[str_len(string) - 1] = '\0';
        str_rev(string);
    } else if (string[0] == '+') {
        str_rev(string);
        string[str_len(string) - 1] = '\0';
        str_rev(string);
    }

    // Convert
    for (int i = 0; i < str_len(string); i++) {
        digit = string[i];
        if ((result == 214748364 && digit > '7' && digit <= '9') ||
            (result == -214748364 && digit > '8' && digit <= '9') ||
            (result > 214748364 && digit >= '0' && digit <= '9') ||
            (result < -214748364 && digit >= '0' && digit <= '9')) {
            if (is_negative) result = -2147483648;
            else result = 2147483647;
            break;
        }
        result *= 10;
        if (digit >= '0' && digit <= '9') {
            if (is_negative) {
                result -= digit - '0';
            } else {
                result += digit - '0';
            }
        } else {
            result /= 10;
            break;
        }
    }

    return result;
}

int main() {
    char string[2024];
    printf("enter a sequence of characters\n");
    scanf("%s", string);
    long integer = myAtoi(string);
    printf("%ld", integer);
    return 0;
}
