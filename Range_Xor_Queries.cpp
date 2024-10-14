#include <bits/stdc++.h>

using namespace std;

// segment tree template ; :)

struct N {
    int x;
     // Default constructor
     N() : x(0) {}
    N(int x_) : x(x_) {} // Parameterized constructor
};

N t[4000100];
vector<int> v;

N merge(N a, N b) {
    N ans(0);
    ans.x = (a.x ^ b.x);
    return ans;
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = N(v[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = merge(t[id << 1], t[id << 1 | 1]);
    return;
}

N query(int id, int start, int end, int lq, int rq) {
    if (end < lq || start > rq) return N(0);
    if (start >= lq && end <= rq) {
        return t[id];
    }
    int mid = (start + end) / 2;
    return merge(query(2 * id, start, mid, lq, rq), query(2 * id + 1, mid + 1, end, lq, rq));
}

int main() {
    int n, q;
    cin >> n >> q;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1); // Don't forget to build the segment tree
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        N ans = query(1, 0, n - 1, a, b);
        cout << ans.x << '\n';
    }

    return 0;
}
