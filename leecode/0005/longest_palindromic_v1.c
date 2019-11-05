#include <stdlib.h>
#include <stdbool.h>

static int strLen(char *);
static bool isPanlindrome(char *str, int start, int end);
static char* subStr(char *s, int start, int end);

/** 返回最长子回文串. */
char * longestPalindrome(char * s){
    if (!s){
        return "";
    }
    int size = strLen(s);
    if (!size){
        return "";
    }
    if (size == 1){
        return s;
    }
    int maxLen = 1;
    int start = 0;
    int end = 0;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (isPanlindrome(s, i, j)){
                if (j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }
    return subStr(s, start, end);
}

/* 判断是否是回文串, 包含start和end. */
bool isPanlindrome(char *str, int start, int end){
    for (int i = start, j = end; i < j; i++, j--){
        if (str[i] != str[j]){
            return false;
        }
    }
    return true;
}

/* 获取字符串长度 */
int strLen(char *s){
    int size = 0;
    while(*s){
        size ++;
        s++;
    }
    return size;
}

char* subStr(char *s, int start, int end){
    char *result = malloc(end - start +1);
    char *tmp = result;
    while(start <= end){
        *tmp = s[start];
        tmp++;
        start++;
    }
    return result;
}
