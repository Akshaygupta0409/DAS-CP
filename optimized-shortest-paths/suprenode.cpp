#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second

const int INF = 1e9;


vector<vector<pair<int,int>>> g;

vector<int> vis,dis;

void dijkstra(int sc,int super_node){
    vis.assign(super_node+1,0);
    dis.assign(super_node+1,INF);
    
    priority_queue<pair<int,int>> pq;
    
    pq.push({-0,sc});
    dis[sc] = 0;
    
    while(!pq.empty()){
        auto xx = pq.top();pq.pop();
        int dd = -xx.F;
        int nn = xx.S;
        
        if(vis[nn]==1)continue;
        vis[nn] = 1;
        
        for(auto v:g[nn]){
            if(vis[v.F]==0 && dd + v.S < dis[v.F]){
                dis[v.F] = dd + v.S;
                pq.push({-dis[v.F],v.F});
            }   
        }
    }
    
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n]; // [1,2,1,3,2]
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]];
    }
    // {(1,0),(2,0),(3,0)}
    int super_node = n+1;
    for(auto v:mp){
        mp[v.F] = super_node;
        super_node++;
    }
    // {(1,6),(2,7),(3,8)}
    // build the graph
    g.resize(super_node);
    for(int i=0;i<n;i++){
        int node_num = i+1;
        int super_node_num = mp[arr[i]];
        
        if(node_num>1){
            g[node_num].push_back({node_num-1,b});
        }
        if(node_num<n){
            g[node_num].push_back({node_num+1,b});
        }
        g[node_num].push_back({super_node_num,a});
        g[super_node_num].push_back({node_num,0});
    }
    // run dijkstra
    dijkstra(1,super_node);

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<endl;
    }
}

int main(){
    solve();
}
