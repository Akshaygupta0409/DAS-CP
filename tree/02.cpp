#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> parent;
vector<int> depth;

void dfs(int node,int par,int dep){
    // at node 
    parent[node] = par;
    depth[node] = dep;
    
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node,dep+1);
        }
    }
}


void solve(){
    int n;
    cin>>n;
    
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    parent.resize(n+1);
    depth.resize(n+1);
    
    dfs(1,0,0);
    
    int max_depth = 0;
    int x = 0;
    for(int i=1;i<=n;i++){
        if(depth[i]>=max_depth){
            x = i;
            max_depth = depth[i];
        }
    }
    
    dfs(x,0,0);
    
    max_depth = 0;
    int y = 0;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<depth[i]<<endl;
        if(depth[i]>=max_depth){
            y = i;
            max_depth = depth[i];
        }
    }
    
    cout<<x<<" to "<<y<<" is a diameter of distance "<< depth[y]<<endl;
    
    if(depth[y]%2==0){
        // 1 center case
        int radius = depth[y]/2;
        int temp = y;
        for(int i=0;i<radius;i++){
            // updating`
            temp = parent[temp];
        }
        
        cout<<"Center is at "<<temp<<endl;
        
    }else{
        // 2 center case
        int radius = depth[y]/2;
        int temp = y;
        for(int i=0;i<radius;i++){
            temp = parent[temp];
        }
        
        cout<<"Center is at "<<temp<<" and "<<parent[temp]<<endl;
    }
    
}

int main(){
    solve();
}