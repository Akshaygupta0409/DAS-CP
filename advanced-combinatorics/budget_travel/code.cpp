#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 10001;
const int MAXC = 101;
const int INF = LLONG_MAX;

int dist[MAXN][MAXC];
bool vis[MAXN][MAXC];
int p[MAXN];
int s, e, c;

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> gr[n + 1];

    
    for (int i = 0; i < m; i++) {
        int u, v, d; cin >> u >> v >> d;
        gr[u].push_back(make_pair(v, d));
        gr[v].push_back(make_pair(u, d));
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cin >> s >> e >> c;
    
    // this intialization is very important 
    for (int i = 1; i <= n; i++) {
        for (int c1 = 0; c1 <= c; c1++) {
            dist[i][c1] = INF;
            vis[i][c1] = false;
        }
    }


    // State: {money, {node, fuel}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[s][0] = 0;
    pq.push({0, {s, 0}});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int money = cur.first;
        int node = cur.second.first;
        int fuel = cur.second.second;

        if (vis[node][fuel]) continue;
        vis[node][fuel] = true;

        // Refuel
        // These state are similar to dp satates and we keep that that state at front on which we are optitimizing 
        if (fuel < c && money + p[node] < dist[node][fuel + 1]) { 
            dist[node][fuel + 1] = money + p[node];
            pq.push({(money + p[node]), {node, fuel + 1}});
        }

        // Travel to neighbors
        for (auto &nbr : gr[node]) {
            int next_node = nbr.first;
            int travel_cost = nbr.second;
            if (fuel >= travel_cost && money < dist[next_node][fuel - travel_cost]) {
                dist[next_node][fuel - travel_cost] = money;
                pq.push({money, {next_node, fuel - travel_cost}});
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= c; i++) {
        ans = min(ans, dist[e][i]);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}