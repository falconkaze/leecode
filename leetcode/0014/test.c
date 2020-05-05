#include <stdio.h>

extern char * longestCommonPrefix(char ** strs, int strsSize);

int main(int argc, char *argv[])
{
    char * strs[3] = {"flower","flow","flight"};
    char * result = longestCommonPrefix(strs, 3);
    printf("%s\n", result);
    return 0;
}
