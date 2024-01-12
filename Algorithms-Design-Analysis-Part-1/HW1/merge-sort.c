#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "/home/shankar/Shiva/prepare-cs2040/include/common.h"
#include <limits.h>

void merge(int a[], int low, int mid, int high)
{
    // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
    int N = high - low + 1;
    int b[N]; // discuss: why do we need a temporary array b?
    int left = low, right = mid + 1, bIdx = 0;

    while (left <= mid && right <= high) // the merging
        b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];

    while (left <= mid)
        b[bIdx++] = a[left++]; // leftover, if any
    while (right <= high)
        b[bIdx++] = a[right++]; // leftover, if any

    for (int k = 0; k < N; ++k)
        a[low + k] = b[k]; // copy back
}

void mergeSort(int a[], int low, int high)
{
    // the array to be sorted is a[low..high]
    if (low < high)
    { // base case: low >= high (0 or 1 item)
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);      // divide into two halves
        mergeSort(a, mid + 1, high); // then recursively sort them
        merge(a, low, mid, high);    // conquer: the merge routine
    }
}

void test()
{
    int a[] = {1, 5, 19, 20, 2, 11, 15, 17};
    int *b = calloc(LEN(a), sizeof(int));
    int N = LEN(a);
    int mid = (N - 1) / 2;
    int left = 0, right = mid + 1, high = N - 1, bIdx = 0;
    printf("left: %d, mid: %d, right: %d, high: %d, bIdx: %d\n\n", left, mid, right, high, bIdx);

    while (left <= mid && right <= high)
    {
        printf("left: %d, mid: %d, right: %d, high: %d, bIdx: %d\n", left, mid, right, high, bIdx);
        if (a[left] <= a[right])
        {
            b[bIdx] = a[left];
            bIdx += 1;
            left += 1;
        }
        else
        {
            b[bIdx] = a[right];
            bIdx += 1;
            right += 1;
        }
    }

    while (left <= mid)
    {
        b[bIdx] = a[left];
        bIdx += 1;
        left += 1;
    }
    while (right <= high)
    {
        b[bIdx] = a[right];
        bIdx += 1;
        right += 1;
    }

    // print the array b
    printf("Array b: ");
    for (int i = 0; i < LEN(a); i += 1)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // read input array : start
    unsigned long long int *input = calloc(100001, sizeof(unsigned long long int));

    unsigned long long int i = 0;

    while (scanf("%llu", &input[i]) != EOF)
    {
        i += 1;
    }
    // read input array : end

    // printf("Input array: ");
    // for (unsigned long long int j = 0; j < 10; j++)
    // {
    //     printf("%llu ", input[j]);
    // }
    // printf("\n");

    int a[] = {1, 5, 19, 20, 2, 11, 15, 17};
    int size = LEN(a);
    mergeSort(a, 0, size - 1);
    printf("Sorted array: ");
    for (int j = 0; j < LEN(a); ++j)
    {
        printf("%d ", a[j]);
    }
    printf("\n");

    return 0;
}
