

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;
const ll N = 300005;
const ll inf = 3e14;
const ll INF = 1e18;

ll n, x, a[N];
ll dp[N][5];

void solve() {
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    // Initialize the dp array with -inf
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j < 5; j++) {
            dp[i][j] = -inf;
        }
    }

    // Base case
    dp[n][0] = 0;
    dp[n][1] = 0;
    dp[n][2] = 0;
    dp[n][3] = 0;

    // Fill the dp table iteratively
    ll ans = 0;
    for (ll pos = n - 1; pos >= 0; pos--) {
        for (ll st = 0; st < 4; st++) {
            if (st == 0) {
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][st]);
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][1] + a[pos]);
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][2] + x * a[pos]);
            } else if (st == 1) {
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][st] + a[pos]);
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][2] + x * a[pos]);
                dp[pos][st] = max(dp[pos][st], 0LL);
            } else if (st == 2) {
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][2] + x * a[pos]);
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][3] + a[pos]);
                dp[pos][st] = max(dp[pos][st], 0LL);
            } else if (st == 3) {
                dp[pos][st] = max(dp[pos][st], dp[pos + 1][3] + a[pos]);
                dp[pos][st] = max(dp[pos][st], 0LL);
            }
            ans = max(ans , dp[pos][st]);

        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
