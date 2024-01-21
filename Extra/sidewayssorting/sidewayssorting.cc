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
#include <stdlib.h> // malloc master
#include <utility>

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
    ll rows = 0, columns = 0;
    char tmp = ' ';
    char line[100];

    if (fgets(line, sizeof(line), stdin) != NULL)
    {
        sscanf(line, "%lld %lld", &rows, &columns); // sscanf
    }

    while ((rows != 0) && (columns != 0))
    {
        vector<vector<char>> char_matrix(rows, vector<char>(columns));

        // Input the char_matrix
        for (ll i = 0; i < rows; i += 1)
        {
            // get a line of input
            if (fgets(line, sizeof(line), stdin) != NULL)
            {
                for (ll j = 0; j < columns; j += 1)
                {
                    // printf("%c", line[j]);
                    char_matrix[i][j] = line[j];
                }
            }
        }
        // End of input the char_matrix

        // Transpose the char_matrix and store in in words
        vector<string> words(columns);
        for (ll i = 0; i < columns; i += 1)
        {
            for (ll j = 0; j < rows; j += 1)
            {
                words[i] += tolower(char_matrix[j][i]);
            }
        }
        // End of transpose

        // Sort the words
        words = insertion_sort(words);

        for (int i = 0; i < columns; i += 1)
        {
            for (int j = 0; j < rows; j += 1)
            {
                char_matrix.at(j).at(i) = words.at(i).at(j);
            }
        }

        // print the words
        for (ll i = 0; i < rows; i += 1)
        {
            for (ll j = 0; j < columns; j += 1)
            {
                printf("%c", char_matrix[i][j]);
            }
            printf("\n");
        }

        // To end the input reading
        if (fgets(line, sizeof(line), stdin) != NULL)
        {
            sscanf(line, "%lld %lld", &rows, &columns); // sscanf
        }
    }

    return 0;
}