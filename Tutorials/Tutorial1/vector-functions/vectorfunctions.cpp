#include "vectorfunctions.h"

// Reverse a vector.
// Note that it is sent as a reference, so you should
// reverse the same vector that was sent in.
void backwards(std::vector<int> &vec)
{
    int size = vec.size();
    // std::cout << "size : " << size / 2 << std::endl;
    for (int i = 0; i < size / 2; i += 1)
    {
        int temp = vec[i];
        vec[i] = vec[size - i - 1];
        vec[size - i - 1] = temp;
    }
    // print array
    // for (int i = 0; i < size; i += 1)
    // {
    //     std::cout << vec[i] << " ";
    // }
}

// Return every other element of the vector, starting with the first.
// You should return a new vector with the answer.
// You are not allowed to modify the vector, even though it is
// sent as a reference. Therefore, the parameter is declared "const".
std::vector<int> everyOther(const std::vector<int> &vec)
{
    // create a new vector
    int size;
    if (vec.size() % 2)
    { // odd
        size = vec.size() / 2 + 1;
    }
    else
    {
        size = vec.size() / 2;
    }

    std::vector<int> newVec(size);

    for (int i = 0; i < size; i += 1)
    {
        newVec[i] = vec[i * 2];
    }

    return newVec;
}

// Return the smallest value of a vector.
int smallest(const std::vector<int> &vec)
{
    int small = vec[0];
    for (size_t i = 1; i < vec.size(); i += 1)
    {
        if (vec[i] < small)
        {
            small = vec[i];
        }
    }
    return small;
}

// Return the sum of the elements in the vector.
int sum(const std::vector<int> &vec)
{
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i += 1)
    {
        sum += vec[i];
    }
    return sum;
}

// Return the number of odd integers, that are also on an
// odd index (with the first index being 0).
int veryOdd(const std::vector<int> &suchVector)
{
    int total = 0;
    for (size_t i = 0; i < suchVector.size(); i += 1)
    {
        if (suchVector[i] % 2 && i % 2)
        {
            total += 1;
        }
    }
    return total;
}