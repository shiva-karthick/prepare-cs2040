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

    /*  Kattis - flowshop
    Observe the pattern.Go row by row, column by column to determine the time the ith swather left the
    jth stage(represented by arr[i][j]).

    Time: O(n ^ 2), Space : O(n ^ 2)
*/

        // Simulate the process.
    // The key observation is that the time one finishes depends on the time each
    // stage is free.
    int n, m;
    cin >> n >> m;
    vector<int> end(m);
    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < m; ++j)
        {
            int t;
            cin >> t;
            cur = max(cur, end[j]) + t;
            end[j] = cur;
        }
        cout << cur << ' ';
    }

    return 0;
}