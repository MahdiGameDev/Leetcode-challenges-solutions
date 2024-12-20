#include <stdlib.h>

int romanToInt(char* s) {
    int result = 0;
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char val = s[i];
        char next = s[i + 1];
        if (val == 'I') {
            result += (next != 'V' && next != 'X') ? 1 : ((next == 'V') ? 4 : 9);
            if (next == 'V' || next == 'X') i++;
        }
        else if (val == 'V') result += 5;
        else if(val == 'X') {
            result += (next != 'L' && next != 'C') ? 10 : ((next == 'L') ? 40 : 90);
            if (next == 'L' || next == 'C') i++;
        }
        else if (val == 'L') result += 50;
        else if (val == 'C') {
            result += (next != 'D' && next != 'M') ? 100 : ((next == 'D') ? 400 : 900);
            if (next == 'D' || next == 'M') i++;
        } 
        else if (val == 'D') result += 500;
        else if (val == 'M') result += 1000;
    }
    return result;
}