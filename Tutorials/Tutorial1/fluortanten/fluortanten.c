#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

int main(void)
{
    // input
    unsigned long long n;
    scanf("%llu", &n);

    long long int *array = malloc(n * sizeof(long long int));

    for (unsigned long long i = 0; i < n; i += 1)
    {
        scanf("%lld", &array[i]);
    }
    // end

    long long int max_sum = LLONG_MIN;
    long long int optimize[3]; // store 3 numbers only
    long long int optimize_count = 1;
    bool visited = false;

    for (unsigned long long i = 0; i < n; i += 1)
    {
        // place 0 at the start of the array, populate the rest of the array with the other elements exluding the 0. get the sum of the array. then repeat by placing 0 at the second element, then the third, etc.
        long long int *temp_array = malloc(n * sizeof(long long int));
        temp_array[i] = 0;
        unsigned long long count = 0;

        // Filling up rest of the temp array
        for (unsigned long long j = 0; j < n;) // j is for the temp array
        {
            // don't overwrite
            if (j != i)
            {
                if (array[count] == 0)
                {
                    count += 1;
                }

                temp_array[j] = array[count];
                count += 1;
                j += 1; // increase count for temp array
            }
            else
            {
                j += 1; // increase count for temp array
            }
        }

        long long int tmp = 0; // Used

        // calculate the total sum of the array
        for (unsigned long long j = 0; j < n; j += 1)
        {
            // printf("%lld ", temp_array[j]);
            tmp += temp_array[j] * (long long int)(j + 1);
        }
        // printf("\n");

        // printf("%lld\n", tmp);
        // Here is where you get the result of the nth permutation of the array
        if (optimize_count != 3)
        {
            optimize[optimize_count - 1] = tmp;
            optimize_count += 1;
        }
        else if (optimize_count == 3)
        {
            // print the array
            // for (unsigned long long j = 0; j < 3; j += 1)
            // {
            //     printf("Hello %lld ", optimize[j]);
            // }
            if ((optimize[0] - optimize[1] == 1) && (optimize[1] - optimize[2] == 2))
            {
                break;
            }
            if ((optimize[1] - optimize[0] == 2) && (optimize[2] - optimize[1] == 1) && !visited)
            {

                i = n - 1;
                visited = true;
            }
        }

        if (tmp > max_sum)
        {
            max_sum = tmp;
        }

        free(temp_array);
    }

    printf("%lld\n", max_sum);

    return 0;
}
