#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
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

ll width, height;
ll house = 0;

pair<int, int> change_direction(pair<int, int> dir, char symbol)
{
    if (symbol == '/')
    {
        //  Draw out the diagram and observe for each case, then only you will understand.
        // I am too dumb to understand without drawing lol, welp
        dir = {dir.second * -1, dir.first * -1};
    }
    else
    {
        dir = {dir.second, dir.first};
    }

    return dir;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    height : Insertion sort
    method insertionSort(array A[], integer N)
      for i in [1..N-1] // O(N)
        let X be A[i] // X is the next item to be inserted into A[0..i-1]
        for j from i-1 down to 0 // this loop can be fast or slow
          if A[j] > X
            A[j+1] = A[j] // make a place for X
          else
            break
        A[j+1] = X // insert X at index j+1
    */

    ll N, tmp, count = 0;
    cin >> N;
    vector<ll> vec(20);
    vec = {};

    for (ll i = 0; i < N; i += 1)
    { // Loop through each test case
        cin >> tmp;
        cout << tmp << ' ';
        for (ll j = 0; j < 20; j += 1)
        { // Loop through all 20 elements
            cin >> tmp;
            vec.push_back(tmp);
        }

        // Insertion sort
        for (ll k = 1; k < 20; k += 1)
        {                    // O(n) time
            ll key = vec[k]; // element 1
            int m = k - 1;
            while ((m >= 0) && (vec[m] > key))
            {
                vec[m + 1] = vec[m];
                m -= 1;
                count += 1;
            }
            vec[m + 1] = key;
        }

        // print the array
        /*for (auto a : vec) {
            cout << a << ' ';
        }
        cout << endl;*/
        cout << count << '\n';
        count = 0; // reset the counter
        vec = {};  // clear the array
    }

    return 0;
}