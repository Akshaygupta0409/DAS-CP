#include <bits/stdc++.h>
using namespace std;

#define ll long long      // shorthand for long long
#define vec vector<ll>
const ll INF = 1e15;

// Global variables for cost and happiness values and DP memoization table.
vec a, b;
vector<vector<ll>> dp;

// Function for modular binary exponentiation.
// Computes (base^exp) % mod efficiently.
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

// Recursive DP function to compute the minimum cost to achieve at least a given happiness.
// Parameters: n - total items, x - cost parameter, i - current index, happy - remaining happiness to achieve.
ll calc(ll n, ll x, ll i, ll happy) {
    if (happy == 0) return 0;             // Base case: Desired happiness reached.
    if (i >= n) return INF;              // No more items to choose from.
    if (dp[i][happy] != -1) return dp[i][happy]; // Return memoized result if available.

    ll take = INF;
    ll not_take = calc(n, x, i + 1, happy);   // Option: Skip current item.

    if (happy - b[i] >= 0)
        take = calc(n, x, i + 1, happy - b[i]) + a[i];  // Option: Take current item and add its cost.

    ll ans = min(take, not_take);
    // Check cost threshold using parameter x (threshold defined as (i-1)*x).
    return dp[i][happy] = (ans < (i-1) * x) ? ans : INF;
}

// Function to process each test case.
void solve() {
    ll n, x, total_happiness = 0;
    cin >> n >> x;  // Read the number of items and cost parameter.

    a.clear();
    b.clear();

    a.resize(n);
    b.resize(n);

    // Read cost 'a' and happiness 'b' for each item and sum total happiness.
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        total_happiness += b[i];
    }

    dp.assign(n, vector<ll>(total_happiness + 1, -1));

    // Iterate from maximum possible happiness down to 0
    // to find the highest achievable happiness level.
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
    cin >> t;  // Read number of test cases.
    while (t--) {
        solve();  // Process each test case.
    }
    return 0;
}
