#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> subtree;
vector<int> depth;
vector<int> parent;

int max_depth,max_depth_node;

void dfs(int node,int par,int dep){
    subtree[node] = 1;
    depth[node] = dep;
    parent[node] = par;
    
    if(dep>max_depth){
        max_depth = dep;
        max_depth_node = node;
    }
    for(auto v:g[node]){
        if(v!=par){
            // child
            dfs(v,node,dep+1);
            subtree[node] += subtree[v];
        }
    }
}


int main()
{
    cin>>n;
    g.resize(n+1);
    
    subtree.resize(n+1);
    depth.resize(n+1);
    par.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    max_depth = -1;
    max_depth_node = 0;
    dfs(1,0,0);
    
    int x = max_depth_node;
    
    max_depth = -1;
    max_depth_node = 0;
    dfs(x,0,0);
    
    int y = max_depth_node;
    
    if(max_depth%2==0){
        // 1 center case
        int c = y;
        for(int i=0;i<(max_depth/2);i++){
            c = parent[c];
        }
        //
        
    }else{
        // 2 center case
        int c1 = y;
        for(int i=0;i<(max_depth/2);i++){
            c1 = parent[c1];
        }
        int c2 = parent[c1];
        
        //
    }
    
    
}