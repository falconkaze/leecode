#include <stdio.h>
#include <stdbool.h>

extern bool isPalindrome(int);

int main(){
    int value = 1221;
    bool result = isPalindrome(value);
    printf("result: %d.\n", result);
    return 0;
}
