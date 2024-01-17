#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 10e15
template <class T>
using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

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

// Variable Declaration and Input
int Row = 0, Col = 0, output = 0;
string tmp;
vector<vector<char>> v;
vector<vector<bool>> visited;

// 8 Direction Flood Fill
int dr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void dfs(int r, int c)
{
    visited[r][c] = true;
    for (int i = 0; i < 8; i += 1) // 8 directions
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // make sure the new position is within the bounds of the grid
        if (nr >= 0 && nr < Row && nc >= 0 && nc < Col && v[nr][nc] == '#' && !visited[nr][nc])
        {
            // I am somewhere in the middle of the grid and I have found a new '#' that I have not visited before
            dfs(nr, nc);
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input starts here
    cin >> Row >> Col;

    v.assign(Row, vector<char>(Col));
    visited.assign(Row, vector<bool>(Col, false));

    for (int i = 0; i < Row; i += 1)
    {
        cin >> tmp;
        for (int j = 0; j < Col; j += 1)
        {
            v[i][j] = tmp[j];
        }
    }
    // Input ends here

    // print out the vector of vectors
    // for (int i = 0; i < Row; i++)
    // {
    //     for (int j = 0; j < Col; j++)
    //     {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // Perform DFS here
    //  What this code does is that it will go through the entire grid and whenever it finds a '#', it will perform a DFS on that position. Then, it will mark all the positions that are connected to that position as visited. This way, we will be able to count the number of connected components in the grid. Then, we will print out the number of connected components.
    for (ll i = 0; i < Row; i += 1)
    {
        for (ll j = 0; j < Col; j += 1)
        {
            if (v[i][j] == '#' && !visited[i][j])
            {
                output += 1;
                dfs(i, j);
            }
        }
    }

    cout << output << endl;

    return 0;
}