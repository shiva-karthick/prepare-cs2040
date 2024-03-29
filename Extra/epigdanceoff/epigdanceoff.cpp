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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input start
    ll N = 0, M = 0, dance_moves = 0; // N rows and M columns
    cin >> N >> M;
    vector<vector<char>> grid;
    string row;

    grid.assign(N, vector<char>(M));

    for (ll i = 0; i < N; i += 1)
    {
        cin >> row;
        for (ll j = 0; j < M; j += 1)
        {
            grid[i][j] = row[j];
        }
    }
    // Input done

    // count the number of blank columns plus one
    for (ll i = 0; i < M; i += 1)
    {
        bool check = true;
        for (ll j = 0; j < N; j += 1)
        {
            if (grid[j][i] == '_')
            {
                check = true;
            }
            else
            {
                check = false;
                break; // go to the next column
            }
        }
        if (check)
        {
            dance_moves += 1;
        }
    }

    cout << dance_moves + 1 << endl;

    return 0;
}