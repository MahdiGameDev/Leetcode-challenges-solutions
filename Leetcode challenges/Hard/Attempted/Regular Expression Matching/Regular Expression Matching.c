#include <stdbool.h>
#include <stdlib.h>


int str_len(char* string) {
    int len = 0;
    while (string[len] != '\0') len++;
    return len;
}

void str_reset(char* string) {
    int i = 0;
    while (string[i] != '\0') i++;
}

void str_cpy(char* destination, char* source) {
    str_reset(destination);
    int len = str_len(source);
    int index = 0;
    while (index < len) {
        destination[index] = source[index++];
    }
    destination[index] = '\0';
}

int* str_chr(char* string, char targetCharacter, int* returnSize) {
    int len = str_len(string);
    int* result = calloc(len, sizeof(int));
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (string[i] == targetCharacter) result[index++] = i;
    }
    (*returnSize) = index;
    return result;
}

void str_del(char* string, int targetIndex) {
    int len = str_len(string);
    char* copy = calloc(len, sizeof(char));
    int index = 0;
    for (int j = 0; j < len; j++) {
        if (j != targetIndex) copy[index++] = string[j];
        else len--;
    }
    str_cpy(string, copy);
}

int checkAndDelet(char* string, char targetCharacter) {
    int cont;
    int* stars = str_chr(string, targetCharacter, &cont);
    return cont;
}

bool passCheck(char* s, char* p) {
    int sSize = str_len(s);
    for (int i = 0; i < sSize; i++) {
        if (p[i] == '*' && s[i] != '*') {
            if (s[i] < '0') return false;
        } else if (s[i] == '*' && p[i] != '*') {
            if (p[i] < '0') return false;
        } else if (p[i] != '.' && s[i] != '.') {
            if (s[i] != p[i] && (s[i + 1] == '*' || p[i + 1] == '*')) return false;
    }
    return true;
}

bool isMatch(char* s, char* p) {
    int sSize = str_len(s);
    int pSize = str_len(p);
    passCheck(s, p);
}