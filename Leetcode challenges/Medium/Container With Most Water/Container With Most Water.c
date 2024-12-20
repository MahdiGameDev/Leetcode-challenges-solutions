#include <stdio.h>

int maxArea(int* arr, int n){
    int Volum = 0, i = 0, j = n - 1;
    while(j > i){
        int tmp = arr[i];
        if(tmp > arr[j]) tmp = arr[j];

        tmp *= (j - i);
        if(Volum < tmp) Volum = tmp;

        if(arr[i] < arr[j]) i++;
        else j--;
    }
    return Volum;
}