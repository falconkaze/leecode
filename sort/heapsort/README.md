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

    堆排序包括三个关键步骤：

    a. 建堆

    b. 交换根结点（第一个元素）和最后一个元素的位置

    c. 构造新的堆（去除最后一个元素的堆），并重复 b 和 c

    ```
    HEAPSORT(A)
        BUILD-MAX-HEAP(A)
        for i = A.length - 1 downto 1
            exchange A[0] with A[i]
            A.heap-size = A.heap-size - 1
            MAX-HEAPIFY(A, 0)
    ```

## 优先队列

    优先队列是一种用来维护由一组元素构成的集合 S 的数据结构，其中的每个元素都有一个相关的值，称为关键字（key）。

    优先队列分为最大优先队列和最小优先队列。一个最大优先队列支持以下操作：

    a. INSERT(S, x)：把元素 x 插入集合 S 中。

    b. MAXIMUM(S)：返回 S 中具有最大 key 的元素。

    c. EXTRACT-MAX(S)：去掉并返回 S 中具有最大 key 的元素。

    d. INCREASE-KEY(S, x, k)：将元素 x 的 key 值增加dao k，这里假设 k 的值不小于 x 原先的值。

    最大优先队列的一个典型应用就是：在共享计算机系统中的作业调度，可以随时添加新作业，并可以选出集合中最高优先级的作业。最小优先队列可以被用于基于事件驱动的模拟器，事件的发生时间作为 key，事件必须按照发生的时间顺序进行模拟，因为一个某一时间的模拟结果可能会出发对其他事件的模拟。

### HEAP-MAXIMUM

    ```
    HEAP-MAXIMUM(A)
        return A[0]
    ```

### HEAP-EXTRACT-MAX

    ```
    HEAP-EXTRACT-MAX(A)
        if A.heap-size < 1
            error "heap underflow"
        max = A[0]
        A[0] = A[A.heap-size - 1]
        A.heap-size -= 1
        MAX-HEAPIFY(A, 0)
        return max
    ```

    时间复杂度 O(lgn)。

### HEAP-INCREASE-KEY

    ```
    HEAP-INCREASE-KEY(A, i, key)
        if key < A[i]
            error "new key is smaller than current key"
        A[i] = key
        while i > 0 and A[PARENT(i)] < A[i]
            exchange A[i] with A[PARENT(i)]
            i = PARENT(i)
    ```

    时间复杂度为 O(lgn)。

### MAX-HEAP-INSERT

    MAX-HEAP-INSERT 首先通过增加一个 key 为 MIN_VALUE 的叶结点来扩展最大堆，然后调用 HEAP-INCRESE-KEY 为新结点设置对应的关键字，同时维持最大堆的性质。

    ```
    MAX-HEAP-INSERT(A, key)
        A.heap-size = A.heap-size + 1
        A[A.heap-size - 1] = MIN_VALUE
        HEAP-INCREMENT-KEY(A, A.heap-size - 1, key)
    ```

    在一个包含 n 个元素的堆中，所有优先队列的操作都可以在 O(lgn) 内完成。
