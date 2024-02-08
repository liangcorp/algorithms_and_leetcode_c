#include <stdio.h>

int mono_increasing(int *array, int n)
{
    int key = 0;
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        key = array[i];

        j = i - 1;

        while (j > -1 && array[j] > key) {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
    return 0;
}
int main()
{
    int n = 10;
    int array[] = {30, 10, 60, 70, 50, 30, 20, 80, 40, 90};
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    if (mono_increasing(array, n) != 0)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
