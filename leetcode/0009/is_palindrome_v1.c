#include <stdbool.h>

bool isPalindrome(int x){
    if (x < 0){
        return false;
    }
    // int 最长为10位.
    char str[10] = {};
    int size = 0;
    int quotient = x, remainder;
    do {
        remainder = quotient % 10;
        str[size] = (char) (remainder + '0');
        quotient /= 10;
        size++;
    }while(quotient);

    for(int i = 0, j = size - 1; j > i; i++, j--){
        if (str[i] != str[j]){
            return false;
        }
    }
    return true;
}
