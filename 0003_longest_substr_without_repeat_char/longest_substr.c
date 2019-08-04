
int lengthOfLongestSubstring(char * s){
    if(!*s){
        return 0;
    }
    char alphabet[256] = {};
    int max = 0, current = 0;
    char *s_point =s, *s_start = s;
    while(*s_point){
        char value = *s_point;
        if(alphabet[(int)value] == 0){
            alphabet[(int)value] = 1;
            current++;
            s_point++;
        }else{
            if(max < current){
                max = current;
            }
            while(1){
                alphabet[(int)*s_start] = 0;
                if(*s_start == *s_point){
                    break;
                }
                current--;
                s_start++;
            }
            alphabet[(int)value] = 1;
            s_start++;
            s_point++;
        }
    }
    return current > max ? current : max;
}
