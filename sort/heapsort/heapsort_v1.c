
void build_max_heap(int*, int);

void max_heapify(int*, int, int);

int left(int);

int right(int);

int parent(int);

void heapsort(int* array, int size)
{
    if (size < 2) {
        return;
    }
    build_max_heap(array, size);
    while (size > 2) {
        int tmp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = tmp;
        size--;
        max_heapify(array, size, 0);
    }
}

void build_max_heap(int* array, int arraySize)
{
    for (int i = (arraySize - 2) / 2; i >= 0; i--) {
        max_heapify(array, arraySize, i);
    }
}

void max_heapify(int* array, int arraySize, int index)
{
    int l = left(index);
    int r = right(index);
    int largest;
    if (l < arraySize && array[l] > array[index]) {
        largest = l;
    } else {
        largest = index;
    }
    if (r < arraySize && array[r] > array[largest]) {
        largest = r;
    }
    if (index != largest) {
        int tmp = array[largest];
        array[largest] = array[index];
        array[index] = tmp;
        max_heapify(array, arraySize, largest);
    }
}

int parrent(int index)
{
    return (index - 1) / 2;
}

int right(int index)
{
    return (index + 1) << 1;
}

int left(int index)
{
    return (index << 1) + 1;
}
