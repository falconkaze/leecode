#include <stdbool.h>

bool isEqual(char, char);

bool isMatch(char * s, char * p){
    char lastChar = 0;
    while (*s && *p){
        if (isEqual(*s, *p)){
            lastChar = *s;
            s++;
            p++;
            continue;
        }
        if (*p == '*'){
            bool isEqual = isEqual(*s, lastChar);
            if (isEqual){
                s++;
                continue;
            }
            // TODO
            return false;
        }
        return false;
    }
}

struct Stack {

    int * array;

    int top;

}

int newStack(int size){
    Stack stack = {malloc(size * sizeof(int)), 0};
}

void destroyStack(Stack stack){
    free(stack->array);
}

bool isEqual(char s, char p){
    if (p == '.'){
        return true;
    }
    return p == s;
}
