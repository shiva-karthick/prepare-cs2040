#include <iostream>
#include <string>
#include <vector>

template <class myType>
myType GetMax(myType a, myType b)
{
    return (a > b ? a : b);
}

template <class T>
class ListArray
{
private:
    int N;
    T A[100]; // This line.
public:
    ListArray() : N(0)
    {
    }
    T get(int i)
    {
        return A[i];
    }
};

int main(int argc, char const *argv[])
{
    // create a vector
    std::vector<int> v = {1, 2, 3, 4, 5};

    // print the vector
    v.push_back(6);
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }

    return 0;
}
