#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>

using namespace std;

using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 10e15
// template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

    ll r, n;
    cin >> r;
    cin >> n;

    vector<bool> array(r + 1);
    ll val;

    // just need to count the number of filled slots
    for (ll i = 0; i < n; i += 1)
    {
        cin >> val;
        array[val] = true;
    }

    cout << "---" << endl;

    for (ll i = 1; i <= r; i += 1)
    {
        if (array[i] != true)
        {
            cout << i << endl;
            return 0;
        }
    }

    for (ll i = 1; i <= r; i += 1)
    {
        if (array[i] != true)
        {
            cout << i << endl;
            return 0;
        }
        else
        {
            cout << "too late" << endl;
            return 0;
        }
    }

    return 0;
}