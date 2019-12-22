# 堆排序

    堆排序的时间复杂度是 O(nlgn)，具有空间原址性（空间复杂度为 O(1)）。堆排序中使用了“堆”这种特殊的数据结构来进行信息管理。

## 堆

    （二叉）堆是一个数组，它可以被看做一个近似的完全二叉树，除了最底层外，该树是完全充满的。树的根结点是数组的第一个元素（A[0]）。

    父结点和左右子结点的关系如下：

    ```
    PARENT(i)
        return (i - 1) / 2

    LEFT(i)
        return 2 * i + 1

    RIGHT(i)
        return 2 * (i + 1)
    ```

    父结点总是在它的子结点的左边。在堆排序的好的实现中，这个函数通常是以“宏”或者“内联函数”的方式实现的。

    二叉堆可以分为两种形式：最大堆和最小堆。在两种堆中，结点的值都要满足堆的性质。在最大堆中，最大堆性质是指除了根以外的所有结点 i 都要满足：`A[PARENT(i)] >= A[i]。也就是说，任意结点的值最多和其父结点一样大。堆中的最大元素存放在根结点中。最小堆的性质相反：除了根以外的所有结点 i 都有：`A[PARENT(i)] <= A[i]`。

    在堆排序算法中，使用的是最大堆。最小堆通常用于构造优先队列。

    一个堆中的结点的高度为该结点到叶结点最长简单路上边的数目，堆的高度就是根结点的高度。

## 堆的基本过程

    堆的一些基本过程：

    a. MAX-HEAPIFY：维护最大堆性质的关键，时间复杂度为 O(lgn)。

    b. BUILD-MAX-HEAP：功能是从一个无序的输入数据数组中构造一个最大堆，具有线性时间复杂度。

    c. HEAP-SORT：功能是对一个数组进行原址排序，时间复杂度为 O(nlgn)。

    d. MAX-HEAP-INSERT、HEAP-EXTRACT-MAX、HEAP-INCREASE-KEY 和 HEAP-MAXIMUM：功能是利用堆实现一个优先队列，时间复杂度为 O(lgn)。

### MAX-HEAPIFY（维护最大堆）

    MAX-HEAPIFY(A, i)：A 是存放堆的数组，i 是数组下标。使用前提是：i 的两个子树都是最大堆；效果是：将根结点为 i 的树转化为最大堆。MAX-HEAPIFY 通过让 A[i] 的值在最大堆中“逐级下降”，从而使得以下标 i 为根结点的子树重新遵循最大堆的性质。

    ```
    MAX-HEAPIFY(A, i)
        l = LEFT(i)
        r  = RIGHT(i)
        if l < A.heap-size and A[l] > A[i]
            largest = l
        else
            largest = i
        if r < A.heap-size and A[r] > A[largest]
            largest = r
        if larget != i
            exchange A[i] with A[largest]
            MAX-HEAPIFY(A, largest)
    ```

    MAX-HEAPIFY 的时间复杂度为 O(h)，h 表示堆的高度。

### BUILD-MAX-HEAPIFY（构建堆）

    ```
    BUILD-MAX-HEAPIFY(A)
        A.heap-size = A.length
        for A = A.length / 2 downto 1
            MAX-HEAPIFY(A, i)
    ```

    BUILD-MAX-HEAPIFY 的时间复杂度为 O(n)，n 表示数组的大小。

### HEAPSORT（堆排序算法）


