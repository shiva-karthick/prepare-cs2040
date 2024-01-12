#include <iostream>
#include <string>

template <class myType>
myType GetMax(myType a, myType b)
{
    return (a > b ? a : b);
}

int main(int argc, char const *argv[])
{
    /*
    1. List ADT
    2. Identify mistakes
    3. Sorting

    */
    int a = GetMax<int>(1, 2);
    std::cout << a << std::endl;

    /* Insertion sort: method insertionSort(array A[], integer N)
    for i in [1..N-1] // O(N)
        let X be A[i] // X is the next item to be inserted into A[0..i-1]

        for j from i-1 down to 0 // this loop can be fast or slow
            if A[j] > X
                A[j+1] = A[j] // make a place for X
            else
                break

        A[j+1] = X // insert X at index j+1
    */
    int arr[] = {5, 2, 4, 6};

    return 0;
}
