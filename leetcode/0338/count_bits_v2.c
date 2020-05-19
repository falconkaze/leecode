/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int* result = malloc((num + 1) * sizeof(int));
    *returnSize = num + 1;
    result[0] = 0;
    int i = 1;
    int power = 1;
    unsigned int nextPower = power << 1;
    // 警惕数字溢出.
    while(nextPower <= num && power < nextPower){
        while(i < nextPower){
            result[i] = result[i ^ power] + 1;
            i ++;
        }
        result[i] = 1;
        i++;
        power = nextPower;
        nextPower = nextPower << 1;
    }
    while(i <= num){
        result[i] = result[i ^ power] + 1;
        i ++;
    }
    return result;
}
