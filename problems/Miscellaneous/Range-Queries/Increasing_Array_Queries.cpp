// Problem: Increasing Array Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2416
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

// Typedef for clarity
#define int long long

void solve() {
    // Input: number of elements and number of queries
    int n, q;
    cin >> n >> q;

    // Read the array
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Compute the next greater element index for each element
    stack<pair<int, int>> st;
    vector<int> next_greater_index(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            next_greater_index[i] = st.top().second;
        }
        st.push({a[i], i});
    }

    // Precompute "up" and "val" tables for range queries
    vector<vector<int>> up(n, vector<int>(20, -1));
    vector<vector<int>> val(n, vector<int>(20, 0));

    for (int i = 0; i < n; i++) {
        up[i][0] = next_greater_index[i];
        if (next_greater_index[i] != -1) {
            val[i][0] = (next_greater_index[i] - i) * a[i];
        }
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
                val[i][j] = val[i][j - 1] + val[up[i][j - 1]][j - 1];
            }
        }
    }

    // Compute prefix sum for efficient range sum queries
    vector<int> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    auto range_sum = [&](int left, int right) -> int {
        return left > 0 ? prefix_sum[right] - prefix_sum[left - 1] : prefix_sum[right];
    };

    // Process each query
    for (int i = 0; i < q; i++) {
        int left, right;
        cin >> left >> right;
        left--, right--; // Convert to 0-based index

        int result = -range_sum(left, right);

        // Traverse using precomputed tables to calculate the result
        for (int bit = 19; bit >= 0; bit--) {
            if (up[left][bit] != -1 && up[left][bit] <= right) {
                result += val[left][bit];
                left = up[left][bit];
            }
        }

        // Add the remaining contribution
        result += (right - left + 1) * a[left];

        // Output the result for the current query
        cout << result << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // Uncomment the line below if there are multiple test cases
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}
