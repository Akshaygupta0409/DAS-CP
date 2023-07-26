#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve()
{
  string s;
  cin >> s;
  int n = s.size();
  int i = -1, j = 0;
  while (j < n)
  {
    int cnt = i == -1 ? 0 : 1;
    while ((i == -1) or ((i + 1 < n) and (s[i + 1] == s[i])))
    {
      cnt++;
      i++;
    }
    cout << s[i];
    // if (cnt != 1)
    cout << cnt;
    if (j <= i)
    {
      i++;
      j = i;
    }
    else
    {
      j++;
      i = j - 1;
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // int _t;cin>>_t;while(_t--)
  solve();

  return 0;
}