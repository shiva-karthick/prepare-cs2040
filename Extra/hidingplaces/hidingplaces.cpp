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
#include <queue>

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

    // How to solve this?
    // 1. Create a graph of the board
    // 2. Run BFS from the starting point
    // 3. Find the maximum distance from the starting point

    ull n = 0;
    cin >> n;
    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (ull i = 0; i < n; i += 1)
    {
        char character;
        int starting_row;
        cin >> character >> starting_row;
        int starting_column = character - 'a'; // 0-indexed column
        starting_row = 8 - starting_row;       // 0-indexed row
        queue<pair<int, int>> q;               // queue of pairs of ints

        q.emplace(starting_row, starting_column); // add the starting point to the queue

        vector<vector<int>> dist(8, vector<int>(8, 1e9));
        // initialize all distances to infinity, except for the starting point.  chessboard is 8x8

        dist[starting_row][starting_column] = 0; // set the starting point distance to 0. The starting point has a distance of 0.

        int current_maximum = 0; // initialize the current maximum distance to 0

        while (q.size()) // while the queue is not empty
        {
            auto [row, column] = q.front();                            // get the front of the queue
            q.pop();                                                   // pop the front of the queue
            current_maximum = max(current_maximum, dist[row][column]); // update the current maximum distance

            for (ll k = 0; k < 8; k += 1)
            {
                int nr = row + dr[k];
                int nc = column + dc[k];
                if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8 ||
                    dist[nr][nc] != 1e9)
                // why do we +1? Because we are moving to the next square, so we add 1 to the distance. Why do we check if the distance is greater than or equal to the current distance? Because we want to find the shortest path, so if the distance is greater than or equal to the current distance, we don't want to update the distance.
                {
                    continue;
                }
                dist[nr][nc] = dist[row][column] + 1;
                q.emplace(nr, nc);
            }
        }
        cout << current_maximum << ' ';
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (dist[i][j] == current_maximum)
                {
                    cout << (char)(j + 'a') << (7 - i + 1) << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}