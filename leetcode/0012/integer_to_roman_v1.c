#include <stdlib.h>

char * intToRoman(int num){
    char * str = malloc(sizeof(char) * 16);
    int i = 0;
    while(num >= 1000){
        str[i++] = 'M';
        num -= 1000;
    }
    if(num >= 900){
        str[i++] = 'C';
        str[i++] = 'M';
        num -= 900;
    }else if(num >= 500){
        str[i++] = 'D';
        num -= 500;
    }else if(num >= 400){
        str[i++] = 'C';
        str[i++] = 'D';
        num -= 400;
    }
    while(num >= 100){
        str[i++] = 'C';
        num -= 100;
    }
    if(num >= 90){
        str[i++] = 'X';
        str[i++] = 'C';
        num -= 90;
    }else if(num >= 50){
        str[i++] = 'L';
        num -= 50;
    }else if(num >= 40){
        str[i++] = 'X';
        str[i++] = 'L';
        num -= 40;
    }
    while(num >= 10){
        str[i++] = 'X';
        num -= 10;
    }
    if(num >= 9){
        str[i++] = 'I';
        str[i++] = 'X';
        num -= 9;
    }else if(num >= 5){
        str[i++] = 'V';
        num -= 5;
    }else if(num >= 4){
        str[i++] = 'I';
        str[i++] = 'V';
        num -= 4;
    }
    while(num >= 1){
        str[i++] = 'I';
        num -= 1;
    }
    while(i < 16){
        str[i++] = '\0';
    }
    return str;
}
