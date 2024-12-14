#include <stdio.h>


int str_len(char* string) { // Get string lenght
    int lenght = 0;
    while (string[lenght] != '\0') lenght++;
    return lenght;
}

void str_rev(char* string) { // Reverse the string
    int len = str_len(string);
    for (int i = 0; i < len/2; i++) {
        char tmp = string[i];
        string[i] = string[len - 1 - i];
        string[len - 1 - i] = tmp;
    }
}

void int_to_str(int integer, char* result) { // Convert an integer into string
    // Check if negative and remove the sign
    int overflow = 0;
    int is_negative = 0;
    if (integer < 0) { 
        is_negative = 1;
        if (integer == -2147483648) {
            integer++;
            overflow = 1;
        }
        integer *= -1;
    }
    // Convert
    int index = 0;
    if (integer == 0) {
        result[index++] = '0';
    } else {
        while(integer > 0) {
            int digit = integer % 10;
            integer /= 10;
            if (index == 0 && overflow) digit++;
            result[index++] = digit + '0';
        }
    } 

    // Adding negative sign
    if (is_negative) result[index++] = '-';

    result[index] = '\0'; // Null terminate the result

    str_rev(result); // Reverse the result to get the correct digits order
}

int str_to_reversed_int(char* integer) { // Convert a string integer into reversed integer
    // Check if negative and remove the sign
    int is_negative = 0;
    if (integer[0] == '-') {
        is_negative = 1;
        str_rev(integer);
        integer[str_len(integer) - 1] = '\0';
        str_rev(integer);
    }

    // Convert
    int result = 0;
    int len = str_len(integer) - 1;
    for (int i = len; i >= 0; i--) {
        char digit = integer[i];
        if (result > 214748364 && integer[i] <= '8') return 0;
        result *= 10;
        result += digit - '0';
    }
    
    if (is_negative) result *= -1;
    return result;
}

int reverse(int x){
    char mediator[2024];
    int_to_str(x, mediator);
    return str_to_reversed_int(mediator);
}

int main() {
    int x;
    scanf("%ld", &x);
    printf("%ld", reverse(x));
    return 0;
}