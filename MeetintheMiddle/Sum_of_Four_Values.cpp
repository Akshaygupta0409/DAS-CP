#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Map to store pair sums and their indices
    unordered_map<ll, pair<ll, ll>> pairSum;

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll currentSum = a[i] + a[j];

            // Check if we have already seen the complement sum that adds up to x
            if (pairSum.find(x - currentSum) != pairSum.end()) {
                auto p = pairSum[x - currentSum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    // Found the solution
                    cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << "\n";
                    return;
                }
            }

            // Store this pair sum in the map
            if (pairSum.find(currentSum) == pairSum.end()) {
                pairSum[currentSum] = {i, j};
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
