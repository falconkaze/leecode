
int maxArea(int* height, int heightSize){
    if (!height || heightSize <= 1){
        return 0;
    }
    int maxArea = 0;
    int i = 0;
    int j = heightSize - 1;
    int minHeight;
    int tmp;
    while(i < j){
        minHeight = height[i] > height[j] ? height[j] : height[i];
        tmp = minHeight * (j - i);
        if (tmp > maxArea){
            maxArea = tmp;
        }
        if (height[i] > height[j]){
            j --;
        }else {
            i ++;
        }
    }
    return maxArea;
}
