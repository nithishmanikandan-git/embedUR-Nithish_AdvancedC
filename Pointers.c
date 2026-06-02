#include <stdio.h>

void rearrangeEvenOdd(int *arr, int size)
{
    int *evenPos = arr;
    int *curr;

    while (evenPos < arr + size && (*evenPos % 2 == 0))
    {
        evenPos++;
    }

    for (curr = evenPos + 1; curr < arr + size; curr++)
    {
        if (*curr % 2 == 0)
        {
            int temp = *curr;
            int *shift = curr;

            while (shift > evenPos)
            {
                *shift = *(shift - 1);
                shift--;
            }

            *evenPos = temp;
            evenPos++;
        }
    }
}

void printArray(int *arr, int size)
{
    int *ptr;

    for (ptr = arr; ptr < arr + size; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 2, 7, 4, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, size);

    rearrangeEvenOdd(arr, size);

    printf("Rearranged Array:\n");
    printArray(arr, size);

    return 0;
}
