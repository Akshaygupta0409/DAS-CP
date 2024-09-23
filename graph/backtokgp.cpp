#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


const ll MOD = 1e9 + 7;
int n, m;
vector<vector<array<int, 2>>> adj;
vector<ll> dist, cnt, d, mnd, mxd;

//State(node):{ min price,node,cnt of min price routes, min lenght path, max lenght path for min price }

void dijktra(int src) {
	dist.assign(n + 1, 1e18);
	cnt.assign(n + 1, 0);
	d.assign(n + 1, 0);
	mnd.assign(n + 1, 0);
	mxd.assign(n + 1, 0);
	dist[src] = 0;
	cnt[src] = 1;
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		int u = x[1];
		if (x[0] > dist[u])continue;
		for (auto y : adj[u]) {
			int v = y[0], w = y[1];
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
				cnt[v] = cnt[u];
				mnd[v] = mnd[u] + 1;
				mxd[v] = mxd[u] + 1;
			}
			else if (dist[v] == dist[u] + w) {
				(cnt[v] += cnt[u]) %= MOD;
				mnd[v] = min({mnd[v], mnd[u] + 1, mxd[u] + 1});
				mxd[v] = max({mxd[v], mnd[u] + 1, mxd[u] + 1});
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	int u, v, w;
	adj.assign(n + 1, vector<array<int, 2>>());
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dijktra(1);
	if (dist[n] == 1e18)cout << -1 << endl;
	else cout << dist[n] << " " << cnt[n] << " " << mnd[n] << " " << mxd[n] << endl;
}
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	// int i = 1;
	// cin >> t;
	while (t--) {
		// cout << "Case #" << i << ": ";
		solve();
		// i++;
	}
	return 0;
}
