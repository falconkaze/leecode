#include <stdio.h>

extern int heapsort(int *, int);

int main(int argc, char** args){
    int array[13] = {12, 14, 2, 4, 45, 656, 90, 3231, 23, 2334, 12, 34, 2};
    int size = sizeof(array) / 4;
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
    heapsort(array, size);
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}
