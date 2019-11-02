#include <stdio.h>
#include <stdlib.h>

int merge_sort(int *, int);

int merge_sort_recursive(int*, int, int);

int merge(int*, int, int, int);

int main(int argc, char** args){
    int array[13] = {12, 14, 2, 4, 45, 656, 90, 3231, 23, 2334, 12, 34, 2};
    int size = sizeof(array) / 4;
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
    merge_sort(array, size);
    for(int i = 0; i < size; i ++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int merge_sort(int * array, int size){
    return merge_sort_recursive(array, 0, size - 1);
}

int merge_sort_recursive(int* array, int start, int end){
    if (end <= start){
        return 0;
    }
    int mid = (start + end) / 2;
    merge_sort_recursive(array, start, mid);
    merge_sort_recursive(array, mid + 1, end);
    merge(array, start, mid, end);
    return 0;
}

int merge(int* array, int start, int mid, int end){
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int* sub1 = malloc(sizeof(int) * size1);
    int* sub2 = malloc(sizeof(int) * size2);
    for (int i = 0; i < size1; i++){
        sub1[i] = array[start + i];
    }
    for (int j = 0; j < size2; j++){
        sub2[j] = array[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < size1 && j < size2){
        if(sub1[i] < sub2[j]){
            array[k] = sub1[i];
            i++;
        }else{
            array[k] = sub2[j];
            j++;
        }
        k++;
    }
    while (i < size1){
        array[k] = sub1[i];
        k++;
        i++;
    }
    while (j < size2){
        array[k] = sub2[j];
        k++;
        j++;
    }
    free(sub1);
    free(sub2);
    return 0;
}
