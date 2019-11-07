
int myAtoi(char * str){
    // 如果str为null或者长度为0，直接返回0.
    if(!str || !*str){
        return 0;
    }
    while (*str == ' '){
        str++;
    }
    char tag = 0;
    long result = 0;
    if(*str == '-'){
        tag = 1;
        str++;
    }else if(*str == '+'){
        tag = 0;
        str++;
    }
    for (int value = *str - '0'; *str && value >=0 && value <=9; str++, value = *str - '0'){
        result = result * 10 + value;
        if (result >= 0x7fffffffL){
            if (tag){
                if (result >= 0x80000000L){
                    return 0x80000000;
                }
            }else{
                return 0x7fffffff;
            }
        }
    }
    return tag ? -1 * result : result;
}
