#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
vector<int> adj[MAXN];
int pairU[MAXN], pairV[MAXN], dist[MAXN];
int N, M, K;

bool bfs() {
    queue<int> Q;
    for (int u = 1; u <= N; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[0]) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[0] != INT_MAX);
}

bool dfs(int u) {
    if (u != 0) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= N; u++) {
            if (pairU[u] == 0 && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int maxPairs = hopcroftKarp();
    cout << maxPairs << endl;
    for (int v = 1; v <= M; v++) {
        if (pairV[v] != 0) {
            cout << pairV[v] << " " << v << endl;
        }
    }
    return 0;
}
