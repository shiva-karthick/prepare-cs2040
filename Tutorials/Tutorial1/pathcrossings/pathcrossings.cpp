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

// print out vector, 1 D array
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

// print a vector of vectors, 2D array
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

struct player
{
    ll player_num;
    pll coordinates;
    ll ping;
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // A struct will hold the player number, pair of x and y coordinates and the ping value, then we will sort the vector of structs by the ping value.

    ll P, N;
    cin >> P; // number of players
    cin >> N; // number of pinsg for each player

    vector<struct player> total(N);

    for (ll i = 0; i < N; i += 1)
    {
        ll player_num, x, y, ping;
        cin >> player_num >> x >> y >> ping;
        total[i].player_num = player_num;
        total[i].coordinates = make_pair(x, y);
        total[i].ping = ping;
    }

    // Add bubble sort here
    sort(total.begin(), total.end(), [](const player &a, const player &b)
         { return a.ping < b.ping; });

    for (ll i = 0; i < N; i += 1)
    {
        cout << total[i].player_num << ' ' << total[i].coordinates.first << ' ' << total[i].coordinates.second << ' ' << total[i].ping << '\n';
    }

    return 0;
}