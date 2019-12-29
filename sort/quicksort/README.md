# 快速排序

    快排使用了分治的思想。

    a. 分解：数组 A[p...r] 被分为两个部分 A[p...q-1] 中的所有元素都小于 A[q]，A[q+1...r] 中的所有元素都小于 A[q]。其中，计算下标 q 也是划分过程的一部分。

    b. 解决：通过递归地调用快速排序，对于两个子数组进行排序。

    c. 合并：因为子数组都是原址排序的，所以原数组已经有序。

    ```
    QUICKSORT(A, p, r)
        if p < r
            q = PARTITION(A, p,  r)
            QUICKSORT(A, p, q - 1)
            QUICKSORT(A, q + 1, r)
    ```

    ```
    PARTITION(A, p, r)
        x = A[r]
        i = p - 1
        for j = p to r - 1
            if A[j] <= 5
                i++
                exchange A[i] with A[j]
        exchange A[i + 1] with A[r]
        return i + 1
    ```

## 算法特点

    快速排序的期望时间复杂度是 O(nlgn)，最差时间复杂度是 O(n^2)，能够进行原址排序。

    最差情况是每次分区都将所有元素分到一个分区内，时间复杂度为 O(n)。最好情况是每次都平均分配，时间复杂度为O(nlgn)。
