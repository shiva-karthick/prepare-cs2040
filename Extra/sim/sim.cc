#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include "bits/stdc++.h"

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

template <typename T>
vector<T> insertion_sort(const vector<T> &vec)
{
    // Stable sort
    vector<T> input;
    input.reserve(vec.size());

    for (const auto &i : vec)
    {
        input.push_back(i);
    }

    for (ll k = 1; k < vec.size(); k += 1)
    {                     // O(n) time
        T key = input[k]; // element 1
        ll m = k - 1;
        while ((m >= 0) && (input[m] > key))
        {
            input[m + 1] = input[m];
            m -= 1;
        }
        input[m + 1] = key;
    }
    return input;
}

inline static bool myComp(const char &lhs, const char &rhs)
{
    return tolower(lhs) < tolower(rhs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Initializations with proper initial conditions
    ll test_cases = 0;
    char line[100];
    string str;

    cin >> test_cases;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the \n from the input buffer before using getline, ignore line

    for (ll i = 0; i < test_cases; i += 1)
    {
        getline(cin, str);
        list<char> v;
        auto it = v.begin();

        for (auto c : str)
        {
            if (c == '[')
            {
                it = v.begin();
            }
            else if (c == ']')
            {
                it = v.end();
            }
            else if (c == '<')
            {
                if (it != v.begin())
                {
                    v.erase(prev(it));
                }
            }
            else
            {
                v.insert(it, c); // insert at the position pointed by the iterator, and return the iterator to the inserted element.
            }
        }

        for (auto c : v)
        {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}