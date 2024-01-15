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

    ll N, t;
    cin >> N;
    cin >> t;
    vll arr(N);

    for (ll i = 0; i < N; i += 1)
    {
        cin >> arr[i];
    }

    // We can also try bubble sort
    for (ll i = 0; i < N; i += 1)
    {
        for (ll j = 0; j < N - 1; j += 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // We can also try merge sort

    // We can also try selection sort

    // We can also try insertion sort

    // print out the array and see for yourself
    // for (ll i = 0; i < N; i += 1)
    // {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';

    switch (t)
    {
    case 1:
    {
        // we can perform binary search on the array, however, we need to sort it first. we shall do the sorting in the main function
        for (ll i = 0; i < N; i += 1)
        {
            ll to_find = 7777 - arr[i];
            if (to_find != arr[i])
            {
                bool y = binary_search(arr.begin(), arr.end(), to_find);
                // cout << "y" << y << '\n';
                if (y)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
        cout << "No";
        break;
    }

    case 2:
    {
        // Use a set to determine if the array contains duplicates
        set<ll> s;
        for (ll i = 0; i < N; i += 1)
        {
            s.insert(arr[i]);
        }
        if (s.size() == N)
        {
            cout << "Unique";
        }
        else
        {
            cout << "Contains duplicate";
        }
        break;
    }

    case 3:
    {

        /*
        The array is ordered. Find and print the integer that appears > N/2 times in the array or print -1 if no such integer exists.

        We can use a map to store the frequency of each element in the array. Then we can iterate through the map and find the element that appears > N/2 times in the array.
        */

        map<ll, ll> m;
        for (ll i = 0; i < N; i += 1) // Performs in O(N) time
        {
            m[arr[i]]++;
        }

        for (auto it = m.begin(); it != m.end(); it++) // Performs in O(N) time
        {
            if (it->second > N / 2)
            {
                cout << it->first << '\n';
                return 0;
            }
        }
        cout << "-1\n";

        // The total run time is O(n) + O(n) = O(2n) = O(n)

        break;
    }

    case 4:
    {
        if (N % 2) // odd
        {
            cout << arr[N / 2] << '\n';
        }
        else // even
        {
            cout << arr[N / 2 - 1] << ' ' << arr[N / 2] << '\n';
        }
        break;
    }

    case 5:
    {
        /*Print integers in array A that fall between a range [100...999] in sorted order;*/
        for (ll i = 0; i < N; i += 1)
        {
            if (arr[i] >= 100 && arr[i] <= 999)
            {
                cout << arr[i] << ' ';
            }
        }
        break;
    }

    default:
        break;
    }

    return 0;
}