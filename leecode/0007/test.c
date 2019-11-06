#include <stdio.h>

extern int reverse(int);

int main(){
    int oldValue = -123;
    int result = reverse(oldValue);
    printf("result: %d.\n", result);
    return 0;
}
