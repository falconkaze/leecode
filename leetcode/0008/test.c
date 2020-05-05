#include <stdio.h>

extern int myAtoi(char *);

int main(){
    char * str = "-2147483647";
    int result = myAtoi(str);
    printf("result: %d.\n", result);
    return 0;
}
