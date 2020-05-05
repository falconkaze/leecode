# 中位数和次序统计量

## 最大值和最小值

### 只求最大值

    ```
    MAXIMUM(A)
        max = A[0]
        for i = 1 to A.length - 1
            if A[i] > max
                max = A[i]
        return max
    ```

    时间复杂度为 O(n)，比较次数为 n - 1 次。

### 只求最小值

    类似求最大值

### 同时求最大值和最小值

    ```
    MAXIMUN(A)
        if (A.length / 2)
            min = A[0]
            max = A[0]
            i = 1
        else
            i = 2
            if A[0] > A[1]
                min = A[1]
                max = A[0]
            else
                min = A[0]
                max = A[1]
        for i to A.length - 1 step 2
            if A[i] > A[i + 1]
                if A[i] > max
                    max = A[i]
                if A[i + 1] < min
                    min = A[i + 1]
            else
                if A[i + 1] > max
                    max = A[i + 1]
                if A[i] < min
                    min = A[i]
    ```

    两个关键点：
    
    1. 一次比较两个元素，先两者比较，之后大的和 max 比较，小的和 min 比较。两个元素共需要3次比较

    2. 如果元素数为奇数，开始时的 min 和 max 都为第一个元素；如果元素数为偶数，开始时的 min 和 max 通过第一个和第二个元素比较来设置。

    总的比较次数最多为 3 (n / 2)（向下取整）。

### 期望为线性时间的求次序统计量的算法

    算法以快速排序的 PARTITION 过程为基础，算法的期望运行时间为 O(n)，最坏情况为 O(n^2)。

    ```
    RANDOMIZED-SELECT(A, p, r, i)
        if p == r
            return A[p]
        q = RANDOMIZED-PARTITION(A, p, r)
        k = q - p + 1
        if i == k
            return A[q]
        else if i < k
            return RANDOMIZED-SELECT(A, p, q - 1, i)
        else
            return RANDOMIZED-SELECT(A, q + 1, r, i - k)
    ```
