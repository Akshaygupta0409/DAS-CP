#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
const ll INF = 1e15;

// Global variables
vec a, b;
vector<vector<ll>> dp;

// Function for modular binary exponentiation
ll binpow(ll base, ll exp, ll mod) {
    base %= mod;
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Recursive function to calculate the minimum cost
ll calc(ll n, ll x, ll i, ll happy) {
    if (happy == 0) return 0;
    if (i >= n) return INF;
    if (dp[i][happy] != -1) return dp[i][happy];

    ll take = INF;
    ll not_take = calc(n, x, i + 1, happy);

    if (happy - b[i] >= 0)
        take = calc(n, x, i + 1, happy - b[i]) + a[i];

    ll ans = min(take, not_take);
    return dp[i][happy] = (ans < (i-1) * x) ? ans : INF;
}

// Main function for each test case
void solve() {
    ll n, x, total_happiness = 0;
    cin >> n >> x;

    a.clear();
    b.clear();

    a.resize(n);
    b.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        total_happiness += b[i];
    }

    dp.assign(n, vector<ll>(total_happiness + 1, -1));

    for (ll happy = total_happiness; happy >= 0; happy--) {
        if (calc(n, x, 0, happy) < INF) {
            cout << happy << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
