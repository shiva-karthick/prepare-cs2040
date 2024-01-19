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

    string s;
    set<string> input;
    vector<string> tmp;
    set<string> output;

    while (cin >> s)
    {
        input.insert(s);
    }

    for (auto ss : input)
    {
        tmp.push_back(ss);
    }

    for (ll i = 0; i < tmp.size(); i += 1)
    {
        for (ll j = 0; j < tmp.size(); j += 1)
        {
            if (i != j)
            {
                output.insert(tmp[i] + tmp[j]);
            }
        }
    }

    for (auto ss : output)
    {
        cout << ss << '\n';
    }

    return 0;
}