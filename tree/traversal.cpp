#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> val;

vector<int> parent;
vector<int> depth;
vector<int> subtree_sz;
vector<int> subtree_sum;

void dfs(int node,int par,int dep){
    // at node 
    cout<<node<<endl;
    parent[node] = par;
    depth[node] = dep;
    
    subtree_sz[node] = 1;
    subtree_sum[node] = val[node];
    
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node,dep+1);
            subtree_sz[node] += subtree_sz[v];
            subtree_sum[node] += subtree_sum[v];
        }
    }
}


void solve(){
    int n;
    cin>>n;
    val.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    parent.resize(n+1);
    depth.resize(n+1);
    subtree_sz.resize(n+1);
    subtree_sum.resize(n+1);
    
    dfs(1,0,0);
    
}

int main(){
    solve();
}