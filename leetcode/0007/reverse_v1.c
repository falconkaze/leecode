
static int maxInt = 0x7fffffff;
static int minInt = 0x80000000;

int reverse(int x){
    if (x == minInt){
        return 0;
    }
    long result = 0;
    // 正负数分开考虑.
    if (x > 0) {
        while(x > 0){
            int tmp = x / 10;
            int value = x % 10;
            x = tmp;
            result = result * 10 + value;
        }
    }else{
        x = -x;
        while(x > 0){
            int tmp = x / 10;
            int value = x % 10;
            x = tmp;
            result = result * 10 + value;
        }
        result = -result;
    }

    if (result > maxInt || result < minInt){
        return 0;
    }
    return (int) result;
}
