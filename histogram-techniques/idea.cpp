#include <bits/stdc++.h>
using namespace std;

long long maxArea(vector<int> &h) {
    // size of input array 
    int n = h.size();
    // stack to keep track o next greatest or smallest elemtn 
    stack<int> st;
    // index of that elemtn 
    vector<int> lftNxtMin(n), rhtNxtMin(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if (st.empty()) {
            lftNxtMin[i] = -1;
        } else {
            lftNxtMin[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if (st.empty()) {
            rhtNxtMin[i] = n;
        } else {
            rhtNxtMin[i] = st.top();
        }
        st.push(i);
    }
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, 1LL * h[i] * (rhtNxtMin[i] - lftNxtMin[i] - 1));
    }
    for(auto it : lftNxtMin) cout << it << ' ';
    cout << endl;
     for(auto it : rhtNxtMin) cout << it << ' ';
    cout << endl;
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long long ans = maxArea(h);
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
      #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}


/* 
i struggled with this formula  rhtNxtMin[i] - lftNxtMin[i] - 1 here
i am taking in account left and right smalletst element add 2 in the answers 
and legth of subarray is (l-1+1) since i added 2 so here i am substracting -1;
*/