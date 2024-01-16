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

    ll N;
    cin >> N;

    // create a set of all lowercase letters a - z
    set<char> letters;
    for (char c = 'a'; c <= 'z'; c++)
        letters.insert(c);

    string s;
    cin.ignore(); // ignore the newline character after N

    for (ll i = 0; i < N; i += 1)
    {
        getline(cin, s);

        // 1. Parse the string to remove all the unnecessary symbols other than alphabets.
        // 2. If a character ifs found, lowercase that character.
        // 3. Remove all characters which are not symbols.

        string parsedString = "";
        for (char c : s)
        {
            if (isalpha(c))
                parsedString += tolower(c);
        }

        // 4. Place all the characters into a set and order them.
        set<char> parsedSet;
        for (char c : parsedString)
            parsedSet.insert(c);

        // 5 . Get the difference between the set of all letters and the set of parsed letters.
        set<char> difference;
        set_difference(letters.begin(), letters.end(), parsedSet.begin(), parsedSet.end(), inserter(difference, difference.begin()));

        // 6. If the difference set is empty, then the string is a pangram.
        if (difference.empty())
            cout << "pangram\n";
        else
        {
            cout << "missing ";
            for (char c : difference)
                cout << c;
            cout << '\n';
        }
        // for (char c : parsedSet)
        // {
        //     cout << c;
        // }
        // cout << '\n';
    }

    return 0;
}