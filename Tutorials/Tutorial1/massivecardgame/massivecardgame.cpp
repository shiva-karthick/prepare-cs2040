#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

// https://visualgo.net/en/sorting?slide=11-2
void merge(unsigned long long a[], unsigned long long low, unsigned long long mid, unsigned long long high)
{
    // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
    unsigned long long N = high - low + 1;
    unsigned long long b[N]; // discuss: why do we need a temporary array b?
    unsigned long long left = low, right = mid + 1, bIdx = 0;
    while (left <= mid && right <= high) // the merging
        b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
    while (left <= mid)
        b[bIdx++] = a[left++]; // leftover, if any
    while (right <= high)
        b[bIdx++] = a[right++]; // leftover, if any
    for (unsigned long long k = 0; k < N; ++k)
        a[low + k] = b[k]; // copy back
}

// https://visualgo.net/en/sorting?slide=11-5
void mergeSort(unsigned long long a[], unsigned long long low, unsigned long long high)
{
    // the array to be sorted is a[low..high]
    if (low < high)
    { // base case: low >= high (0 or 1 item)
        unsigned long long mid = (low + high) / 2;
        mergeSort(a, low, mid);      // divide into two halves
        mergeSort(a, mid + 1, high); // then recursively sort them
        merge(a, low, mid, high);    // conquer: the merge routine
    }
}

int main(void)
{
    // input start
    unsigned long long int N;
    scanf("%llu", &N);
    unsigned long long int *cards = (unsigned long long int *)malloc(N * sizeof(unsigned long long int));
    for (unsigned long long int i = 0; i < N; i++)
    {
        scanf("%llu", &cards[i]);
    }
    // input end

    // bubble sort the cards array
    // for (unsigned long long int i = 0; i < N; i += 1)
    // {
    //     for (unsigned long long int j = i + 1; j < N; j += 1)
    //     {
    //         if (cards[i] > cards[j])
    //         {
    //             unsigned long long int temp = cards[i];
    //             cards[i] = cards[j];
    //             cards[j] = temp;
    //         }
    //     }
    // }

    mergeSort(cards, 0, N - 1);

    // print cards array
    for (unsigned long long int i = 0; i < N; i += 1)
    {
        printf("%llu ", cards[i]);
    }
    printf("\n");

    unsigned long long int no_ranges = 0;
    scanf("%llu", &no_ranges);
    unsigned long long L, R;

    // for each range ...
    for (unsigned long long int i = 0; i < no_ranges; i += 1)
    {
        scanf("%llu %llu", &L, &R);
        // printf("%llu, %llu\n", L, R);

        unsigned long long int count = 0;
        for (unsigned long long int j = 0; j < N; j += 1)
        {
            if (cards[j] >= L && cards[j] <= R)
            {
                count += 1;
            }
        }
        printf("%llu\n", count);
    }
    return 0;
}
