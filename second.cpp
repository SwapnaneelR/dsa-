#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// vector<int> f(vector<int> t)
// {

//   return t;
// }
bool check(vector<int> v)
{
  // v= f(v);
  map<int, int> hash;
  for (auto i : v)
    hash[i]++;
  return (hash[1] > 0 && hash[2] > 0 && hash[3] > 0);
}

int main()
{
  // your code goes here
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    vector<int> v(n);
    // int one = 0, two = 0, three = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }

    int ans = 0;
    for (int i = 0; i <= v.size() - 1; i++)
    {
      vector<int> t = v;
      for (int j = i; j < n; j++)
      {

        // t.push_back(v[i]);
        for (int i = i; i < j; i++)
        {
          if (t[i] == 3)
            t[i] = 1;
          else
            t[i] = (t[i] + 1);
        }

        if (check(t))
          ans++;
        // cout << "ans = " << ans<<endl;
      }
    }

    // int ans = (one + two + three) * ((one + two + three) + 1) / 2;

    cout << ans << endl;
  }
}
