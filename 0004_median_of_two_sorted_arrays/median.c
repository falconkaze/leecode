#include<stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int merge_nums_size = nums1Size + nums2Size;
    int *merge_nums = malloc(sizeof(int) * merge_nums_size);
    int *point = merge_nums;
    int i = 0, j = 0;
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]){
            *point = nums1[i];
            i++;
        }else{
            *point = nums2[j];
            j++;
        }
        point++;
    }
    while(i < nums1Size){
        *point = nums1[i];
        point++;
        i++;
    }
    while(j < nums2Size){
        *point = nums2[j];
        point++;
        j++;
    }
    
    double result;
    if(merge_nums_size % 2){
        result = merge_nums[merge_nums_size / 2];
    }else{
        int mid = merge_nums_size / 2;
        result = (merge_nums[mid - 1] + merge_nums[mid]) / 2.0;
    }
    free(merge_nums);
    return result;
}
