/*
https://www.learning.algozenith.com/problems/Partial-Sum-on-Tree-452
*/
// Problem: https://www.spoj.com/problems/QTREE2/


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 +7;

vector<vector<ll>> adj, par;
vector<ll> depth, partial;

void dfs(ll node, ll parent, ll dep){
    par[node][0]=parent;
    depth[node]=dep;
    for(ll i=1; i<20; i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }

    for(auto ch:adj[node]){
        if(ch!=parent){
            dfs(ch, node, dep+1);
        }
    }
    // Since we are usinf bottom up approach
    // we will add the partial sum of the node to its parent
    partial[par[node][0]] += partial[node];
}

void addAll(ll node, int parent){
    for(auto ch:adj[node]){
        if(ch!=parent){
            addAll(ch, node);
        }
    }
    partial[par[node][0]] += partial[node];

}

ll LCA(ll u, ll v){
    if(depth[u]<depth[v]){
        swap(u, v);
    }
    for(ll i=19; i>=0; i--){
        if((depth[u]-depth[v])&(1<<i)){
            u=par[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(ll i=19; i>=0; i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

void addX(int u, int v, int x){
    partial[u] += x;
    partial[v] += x;
    int lca = LCA(u, v);
    partial[lca] -= x;
    partial[par[lca][0]] -= x;
}

void solve(){
    ll N;
    cin>>N;
    adj=vector<vector<ll>>(N+1);
    par=vector<vector<ll>>(N+1, vector<ll>(21, 0));
    partial=vector<ll>(N+1, 0);
    depth=vector<ll>(N+1, 0);

    for(int i=1; i<N; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll query;
    cin>>query;
    dfs(1, 0, 0);
    while(query--){
        ll u, v, z;
        cin>>u>>v>>z;
        addX(u, v, z);
    }
    addAll(1, 0);
    for(int i=1; i<=N; i++){
        cout<<partial[i]<<" ";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}