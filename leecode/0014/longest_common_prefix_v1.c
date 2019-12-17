#include <stdlib.h>
#include <string.h>

struct List{
    char * array;
    int index;
    int size;
};

struct List createList(int);

int addList(struct List *, char);

char * longestCommonPrefix(char ** strs, int strsSize){
    if(!strs || strsSize < 1){
        return "";
    }
    struct List list = createList(10);
    char value;
    char * dest;
    int size;
    for(int i = 0; strs[0][i]; i ++){
        value = strs[0][i];
        for(int j = 1; j < strsSize; j++){
            if(strs[j][i] != value){
                goto label;
            }
        }
        addList(&list, value);
    }
label:
    size = list.index + 1;
    dest = malloc(size);
    memcpy(dest, list.array, list.index);
    free(list.array);
    dest[size - 1] = '\0';
    return dest;
}

struct List createList(int size){
    struct List list = {(char*)malloc(sizeof(char) * size), 0, size};
    return list;
}

int addList(struct List *list, char value){
    list->array[list->index++] = value;
    if(list->index >= list->size){
        int newSize = list->size * 1.5;
        char * dest = malloc(sizeof(char) * newSize);
        memcpy(dest, list->array, list->size);
        free(list->array);
        list->array = dest;
        list->size = newSize;
    }
    return 1;
}
