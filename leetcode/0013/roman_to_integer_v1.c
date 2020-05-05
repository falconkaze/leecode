
int romanToInt(char *s){
    int result = 0;
    int last = 1000;
    while(*s){
        switch(*s){
            case 'M':
                if(last < 1000){
                    result += 800;
                    last = 900;
                }else {
                    result += 1000;
                    last = 1000;
                }
                break;
            case 'D':
                if(last < 500){
                    result += 300;
                    last = 400;
                }else {
                    result += 500;
                    last = 500;
                }
                break;
            case 'C':
                if(last < 100){
                    result += 80;
                    last = 90;
                }else {
                    result += 100;
                    last = 100;
                }
                break;
            case 'L':
                if(last < 50){
                    result += 30;
                    last = 40;
                }else {
                    result += 50;
                    last = 50;
                }
                break;
            case 'X':
                if(last < 10){
                    result += 8;
                    last = 9;
                }else {
                    result += 10;
                    last = 10;
                }
                break;
            case 'V':
                if(last < 5){
                    result += 3;
                    last = 4;
                }else {
                    result += 5;
                    last = 5;
                }
                break;
            case 'I':
                result += 1;
                last = 1;
        }
        s++;
    }
    return result;
}
