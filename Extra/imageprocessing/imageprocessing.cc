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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll rows_image, columns_image, rows_filter, columns_filter;

    cin >> rows_image >> columns_image >> rows_filter >> columns_filter;

    vector<vector<ll>> image(rows_image, vector<ll>(columns_image, 0));
    vector<vector<ll>> filter(rows_filter, vector<ll>(columns_filter, 0));

    ll output_rows = rows_image - rows_filter + 1;
    ll output_columns = columns_image - columns_filter + 1;

    vector<vector<ll>> output(output_rows, vector<ll>(output_columns, 0));

    // get input
    for (ll i = 0; i < rows_image; i += 1)
    {
        for (ll j = 0; j < columns_image; j += 1)
        {
            cin >> image[i][j];
        }
    }

    for (ll i = 0; i < rows_filter; i += 1)
    {
        for (ll j = 0; j < columns_filter; j += 1)
        {
            cin >> filter[i][j];
        }
    }
    // end of get input

    for (ll i = 0; i < output_rows; i += 1)
    {
        for (ll j = 0; j < output_columns; j += 1)
        {
            ll sum = 0;
            for (ll k = 0; k < rows_filter; k += 1)
            {
                for (ll l = 0; l < columns_filter; l += 1)
                {
                    sum += image[i + k][j + l] * filter[rows_filter - k - 1][columns_filter - l - 1];
                }
            }
            output[i][j] = sum;
        }
    }

    for (ll i = 0; i < output_rows; i += 1)
    {
        for (ll j = 0; j < output_columns; j += 1)
        {
            cout << output[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}