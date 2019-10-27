#include <stdio.h>

int insert_sort(int *, int);

int main(int argc, char** args){
    int array[13] = {12, 14, 2, 4, 45, 656, 90, 3231, 23, 2334, 12, 34, 2};
    int size = sizeof(array) / 4;
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
    insert_sort(array, size);
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int insert_sort(int *array, int size){
    int value;
    for (int i = 1; i < size; i ++){
        value = array[i];
        int j = i - 1;
        while (j >= 0 && value < array[j]){
            array[j + 1] = array[j];
            j --;
        }
        array[j + 1] = value;
    }
    return 0;
}
