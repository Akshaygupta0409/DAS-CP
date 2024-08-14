#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> adj[MAXN];
long long in[MAXN], out[MAXN], cnt[MAXN], ans;
int n, k;

void dfs1(int v, int p){
    in[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs1(u, v);
        in[v] += in[u];
    }
    cnt[in[v]]++;
}

void dfs2(int v, int p){
    out[v] = out[p] + in[p] - in[v];
    cnt[out[v]]++;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs2(u, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    for(int i = 1; i <= n; i++){
        if(i < k) ans += in[i] * (cnt[k-i] - 1);
        else ans += in[i] * cnt[k-i];
    }

    cout << ans/2 << "\n";

    return 0;
}
