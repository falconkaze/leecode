
int maxArea(int* height, int heightSize){
    if (!height || heightSize <= 1){
        return 0;
    }
    int i = 0;
    int j = heightSize - 1;
    int minHeight;
    int maxArea = 0;
    int tmp;
    while(i < j){
        minHeight = height[i] > height[j] ? height[j] : height[i];
        tmp = minHeight * (j - i);
        if (tmp > maxArea){
            maxArea = tmp;
        }
        if (height[i] > height[j]){
            j--;
            while(j > i && height[j] <= minHeight){
                j--;
            }
        }else {
            i++;
            while(j > i && height[i] <= minHeight){
                i++;
            }
        }
    }
    return maxArea;
}
