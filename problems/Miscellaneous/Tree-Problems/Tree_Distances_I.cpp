#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> indp, outdp, ans;

void indfs(int n = 1, int p = 0) {
    indp[n] = 0;
    for (int c : tree[n]) {
        if (c == p) continue;
        indfs(c, n);
        indp[n] = max(indp[n], indp[c] + 1);
    }
}

void outdfs(int n = 1, int p = 0) {
    // Collect all child depths
    vector<int> childDepths;
    for (int c : tree[n]) {
        if (c != p) {
            childDepths.push_back(indp[c]);
        }
    }

    // Sort to easily find the largest and second largest
    sort(childDepths.rbegin(), childDepths.rend());
    // still don't know why 0 false some testcase and -1 don't fail  
    int largest = childDepths.empty() ? -1 : childDepths[0];
    int secondLargest = childDepths.size() > 1 ? childDepths[1] : -1;
    // Propagate the outdp to children
    for (int c : tree[n]) {
        if (c == p) continue;
        int use = (indp[c] == largest) ? secondLargest : largest; 
        outdp[c] = max(outdp[n] + 1, use + 2);
        outdfs(c, n);
    }
}

void solve() {
    int n;
    cin >> n;
    tree.resize(n + 1);
    indp.resize(n + 1, 0);
    outdp.resize(n + 1, 0);
    ans.resize(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    indfs();
   // outdp[1] = 0; 
    outdfs();

    for (int i = 1; i <= n; i++) {
        ans[i] = max(indp[i], outdp[i]);
        cout << ans[i] << " ";
    }
    cout << '\n';
    tree.clear();
    indp.clear();
    outdp.clear();
    ans.clear();
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
