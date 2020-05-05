#include "longest_palindromic.h"

int main(int argc, char *argv[]){
    char *str = "test";
    printf("result: %s.\n", str);
    char *result = longestPalindrome(str);
    printf("result: %s.\n", result);
    return 0;
}
