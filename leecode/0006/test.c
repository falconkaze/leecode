#include <stdio.h>
#include <stdlib.h>

extern char * convert(char *, int numRows);

int main(){
    char * str = "PAYPALISHIRING";
    char * result = convert(str, 3);
    printf("result: %s.\n", result);
    free(result);
}
