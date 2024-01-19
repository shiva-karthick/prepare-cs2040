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

    // 	2D array checks; 8 directions
    // count the 9 knights
    vector<vector<char>> grid;
    string row;
    grid.assign(5, vector<char>(5));

    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (ll i = 0; i < 5; i += 1)
    {
        cin >> row;
        for (ll j = 0; j < 5; j += 1)
        {
            grid[i][j] = row[j];
        }
    }

    ll count = 0;
    for (ll i = 0; i < 5; i += 1)
    {
        for (ll j = 0; j < 5; j += 1)
        {
            if (grid[i][j] == 'k')
            {
                count += 1;
                // check all possible 8 directions
                for (ll k = 0; k < 8; k += 1)
                {
                    ll r = i + dr[k];
                    ll c = j + dc[k];
                    if (r >= 0 && r < 5 && c >= 0 && c < 5 && grid[r][c] == 'k')
                    {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (count == 9)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}