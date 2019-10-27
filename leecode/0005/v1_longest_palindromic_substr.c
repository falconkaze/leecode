
char * longestPalindrome(char * s){
    int maxLen = 1;
    int size = strLen(s);
    char *result = malloc(size);
    for (int i = 0; i < N; i ++){
        for (int j = i + 2; j < N; i ++){
            if (isPanlindrome(s, i, j)){
                if (j - i + 1 > maxLen){
                    maxLen = j - i + 1;
}

bool isPanlindrome(char *str, int start, int end){
    for (int i = start, j = end; i < j; start ++, end ++){
        if (str[start] != str[end]){
            return false;
        }
    }
    return true;
}

int strLen(char *s){
    int size = 0;
    while(*s){
        size ++;
    }
    return size;
}

char* subStr(char *s, int start, int end){
    char *result = malloc(end - start + 1);
}
