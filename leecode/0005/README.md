# 最长回文子串

## 问题分析

问题是找出最长的回文子串，那么可以将问题分为两步：遍历所有的子串，判断每个子串是不是回文串。

### 判断是否是回文串

判断一个字符串是否是回文串，有两种方法：

1. 从两端到中间

2. 从中间到两端

仅从判断一个字符串是否是回文串来说，这两种方法没什么区别，复杂度都是 O(n)。但是方法二判断过程中可以找出从指定中点遍历的最长回文串，而题目就是需要寻找最长回文串，所以方法二更适合一些。

### 遍历所有子串

字符串有两个特征值：起点，终点，中点，长度，四选二。遍历所有子串也就是说要遍历所有可能的两个特征值。

假设字符串起点是 0，长度是 N，终点是 N-1，`isPanlindrome(char *str)` 判断 str 是否是回文串，`subStr(char *str, int start, int end)` 获取子串（包含 start，end）。

下面分析几种遍历过程，如下：

1. 起点，终点

    ```code
    for i = 0 to N-1 by 1
        for j = i + 2 to N - 1 by 1
            subStr = subStr(str, i, j)
            if (isPanlindrome(subStr))
                if (j - i + 1> maxLend)
                    maxLen = j - i + 1
                    longestStr = substr(str, i, j)
    return longestStr;
    ```

    上面的伪代码的起点是从左向右遍历，终点也是从左向右遍历，两者都可以改成从右向左遍历。或者改成先遍历终点，再遍历起点等等。

2. 起点，长度

    先遍历起点，再遍历长度，这种方法类似于 1，不作分析。

    先遍历长度，再遍历起点：

    ```code
    for subLen = N to 2 by -1                       // 两种遍历方法，从小到大和从大到下，但是题目是找最长的回文子串，所以后者更高效
        for start = N - subLen to 0  by 1            // 两种遍历方式，从左到右和从右到左，但是右边边界点和长度有关（会变化），所以从右向左遍历更高效
            subStr = subStr(str, start, start + subLen - 1)
            if (isPanlindrome(subStr)
                maxLen = subLen
                return subStr
    maxLen = 1
    return subStr(str, 0, 0)
    ```

    上面运算过程中会计算出子串，但是并不是必要的，可以先判断是否是回文串，然后再计算子串（修改 isPanlindrome 函数。

3. 中点，长度

    先遍历长度，再遍历中点：

    ```code
    for subLen = N to 2 by -1
        for start = N - subLen to 0  by 1            // 两种遍历方式，从左到右和从右到左，但是右边边界点和长度有关（会变化），所以从右向左遍历更高效
            subStr = subStr(str, start, start + subLen - 1)
            if (isPanlindrome(subStr)
                maxLen = subLen
                return subStr
    maxLen = 1
    return subStr(str, 0, 0)
    ```

## 暴力穷举法

解析所有子串，然后找出最长的回文子串。

## 递归

## 注意点

1. 长度为 1 的字符串一定为回文串，注意边界的选择。
