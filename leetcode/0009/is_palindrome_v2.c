#include <stdbool.h>

bool isPalindrome(int x){
    if (x < 0){
        return false;
    }
    int tmp = x;
    long result = 0;
    while (tmp){
        int value = tmp % 10;
        tmp /= 10;
        result = result * 10 + value;
    }
    return result == x;
}
