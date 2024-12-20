#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int num = x; // Copy
    unsigned int rev = 0; // Hold the reverse number
    while(x > 0){ // The negative numbers aren't palindrome
        // Calcul the reverse number
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return (rev == num); // Check and return
}

int main() {
    int x;
    printf("Enter a number :\n");
    scanf("%d", &x);
    if (isPalindrome(x)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}