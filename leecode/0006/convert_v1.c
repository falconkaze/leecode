#include <stdlib.h>

static int strLen(char *);

char * convert(char *s, int numRows){
    int size = strLen(s);
    char *result = malloc(size * sizeof(char));
    int start;
    int index = 0;
    int maxLine = numRows - 1;
    for (int i = 0; i < numRows; i++){
        start = i;
        if (i == 0 || i == maxLine){
            while(start < size){
                result[index] = s[start];
                index++;
                start += 2 * maxLine;
            }
        }else{
            int tag = 0;
            while(start < size){
                result[index] = s[start];
                index++;
                tag ^= 1;
                start += (tag * (maxLine - i) + (1 - tag) * (i - 0)) * 2;
            }
        }
    }
    return result;
}

int strLen(char *s){
    int size = 0;
    while(*s){
        size++;
        s++;
    }
    return size;
}
