#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 10e15
// template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

// print out vector
void printVector(vll &v)
{
    ll N = v.size();
    cout << '[';
    if (!N)
        cout << ']';
    for (size_t i = 0; i < N; i++)
    {
        cout << v[i];
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vll> &v)
{
    ll N = v.size();
    for (size_t i = 0; i < N; i++)
    {
        cout << "index: " << i << ' ';
        printVector(v[i]);
    }
    cout << '\n';
}
template <typename T, std::size_t Row, std::size_t Col>
void printArray(std::array<std::array<T, Col>, Row> &arr)
{
    for (const auto &arow : arr) // get each array row
    {
        for (const auto &e : arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}