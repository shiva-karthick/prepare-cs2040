#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 10e15
template <class T>
using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or
// less<T> for PQ_min

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

  // Use bubble sort
  vll array(5);

  for (ll i = 0; i < 5; i += 1)
  {
    cin >> array[i];
  }

  // for (ll i = 0; i < 5; i += 1)
  // {
  //   cout << array[i] << " ";
  // }

  for (ll i = 0; i < 5; i += 1)
  {
    for (ll j = 0; j < 5 - 1; j += 1)
    {
      if (array[j] > array[j + 1])
      {
        swap(array[j], array[j + 1]);
        for (ll k = 0; k < 5; k += 1)
        {
          cout << array[k] << " ";
        }
        cout << '\n';
      }
    }
  }

  return 0;
}
