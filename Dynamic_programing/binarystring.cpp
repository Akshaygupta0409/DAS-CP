#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define nl '\n'
#define F first
#define S second
#define MP make_pair
#define fa false
#define tr true
using namespace std;
using ii = pair<long long, long long>;
// using lli = long long int ;
using vi = vector<long long>;
using vv = vector<vector<long long>>;
using vpi = vector<pair<long long, long long>>;

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// main logic

int n;
int k;
int dp_cache[1010][2][1010];
bool vis[1010][2][1010];

int dp(int i, int p, int l)
{ // base case
    if (i == n)
    {
        return (l >= 0 ? 1 : 0);
    }
    // pruning
    if (l <= 0)
        return 0;
    // cache
    if (vis[i][p][l])
        return dp_cache[i][p][l];
    // transition
    int ans = 0;

    if (p == 0)
    {
        ans = dp(i + 1, 1, k) + dp(i + 1, 0, l - 1);
    }
    else
    {
        ans = dp(i + 1, 0, k) + dp(i + 1, 1, l - 1);
    }

    vis[i][p][l] = true;
    return dp_cache[i][p][l] = ans;
}

void solve()
{
    cin >> n >> k;

    // cacheing setup
    for (int i = 0; i < n + 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n + 3; k++)
            {
                dp_cache[i][j][k] = -249;
                vis[i][j][k] = false;
            }
        }
    }
    cout << dp(0, 0, k) << nl;
    return;
}

#undef int

int main()
{
    init_code();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}


/*
did you get your mistake you were struggleing with man

*/