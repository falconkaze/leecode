#include <stdio.h>

extern char * intToRoman(int num);

int main(){
    char * str = intToRoman(3);
    printf("%s\n", str);
    return 0;
}
