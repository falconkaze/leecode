
int partition(int*, int, int);

void quick_sort_assist(int* array, int p, int r);

void quick_sort(int* array, int size)
{
    quick_sort_assist(array, 0, size - 1);
}

void quick_sort_assist(int* array, int p, int r)
{
    if (p < r) {
        int q = partition(array, p, r);
        quick_sort_assist(array, p, q - 1);
        quick_sort_assist(array, q + 1, r);
    }
}

int partition(int* array, int p, int r)
{
    int value = array[r];
    int i = p;
    int j = p;
    while (j < r) {
        if (array[j] <= value) {
            int tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
            i++;
        }
        j++;
    }
    int tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
    return i;
}
