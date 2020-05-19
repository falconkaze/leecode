/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int* result = malloc((num + 1) * sizeof(int));
    *returnSize = num + 1;
    result[0] = 0;
    while(num){
        int bitNum = 0;
        for(int i = 0; i < 32; i++){
            bitNum += num >> i & 1;
        }
        result[num--] = bitNum;
    }
    return result;
}
