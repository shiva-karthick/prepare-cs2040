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
    Kattis funhouse
    Bump light off mirrors tilted at 45 degrees angle.
    Time complexity: O(w*l*t), where t is the number of testcases.

    Constraints: An exit should not appear in the corner, and an entrance is != exit.
    */

    while (cin >> width >> height)
    {
        if (width == 0 && height == 0)
        {
            break;
        }

        house += 1;
        cout << "HOUSE " << house << endl;
        // cout << "width : " << width << "height : " << height << endl;
        vector<vector<char>> grid(height, vector<char>(width));
        pair<int, int> start;
        pair<int, int> dir;

        for (ll i = 0; i < height; i += 1)
        {
            for (ll j = 0; j < width; j += 1)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '*')
                {
                    start = {i, j};
                    if (j == 0)
                    {
                        // left side
                        dir = {0, 1};
                    }
                    else if (j == width - 1)
                    {
                        // right side
                        dir = {0, -1};
                    }
                    else if (i == 0)
                    {
                        // top side
                        dir = {1, 0};
                    }
                    else if (i == height - 1)
                    {
                        // bottom side
                        dir = {-1, 0};
                    }
                }
            }
        }

        start = {start.first + dir.first, start.second + dir.second};

        // bounce off the mirrors until you reach 'x'.
        while (start.first > 0 && start.first < height - 1 && start.second > 0 && start.second < width - 1)
        {

            if (grid[start.first][start.second] == '/')
            {
                dir = change_direction(dir, '/');
            }
            else if (grid[start.first][start.second] == '\\')
            {
                dir = change_direction(dir, '\\');
            }

            // update the start positions
            start = {start.first + dir.first, start.second + dir.second};
        }
        // where are we after the while loop???
        // we are somewhere in the xxxxx exterior of the grid?
        grid[start.first][start.second] = '&';

        // print the grid
        for (ll i = 0; i < height; i += 1)
        {
            for (ll j = 0; j < width; j += 1)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}