#include <bits/extc++.h>
#include <stdlib.h>

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
    // get the input
    getline(cin, s);

    // get the length of the string
    ll N = s.length();
    ll whitespace = 0, lowercase = 0, uppercase = 0, symbol = 0;

    for (ll i = 0; i < N; i += 1)
    {
        // check if the character is a space
        if (ll(s[i]) == 95)
        {
            whitespace += 1;
            continue;
        }

        // check if the character is uppercase
        if (isupper(s[i]))
        {
            uppercase += 1;
            continue;
        }

        // check if the character is lowercase
        if (islower(s[i]))
        {
            lowercase += 1;
            continue;
        }

        // if the character is not a space, uppercase or lowercase, it is a symbol
        symbol += 1;
    }

    // cout << "whitespace: " << whitespace << '\n';
    // print the ratio of whitespace, lowercase, uppercase and symbol
    cout << fixed << setprecision(15) << static_cast<double>(whitespace) / static_cast<double>(N) << '\n';
    cout << fixed << setprecision(15) << static_cast<double>(lowercase) / N << '\n';
    cout << fixed << setprecision(15) << static_cast<double>(uppercase) / N << '\n';
    cout << fixed << setprecision(15) << static_cast<double>(symbol) / N << '\n';

    return 0;
}