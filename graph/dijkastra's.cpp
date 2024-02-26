#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second

const int INF = 1e9;

int n,m;
vector<vector<int>> g;

vector<int> vis,dis;

void dijkstra(vector<int> sc){
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    
    priority_queue<pair<int,int>> pq;
    
    for(auto v:sc){
        pq.push({-0,v});
        dis[sc] = 0;
    }
    
    
    while(!pq.empty()){
        auto xx = pq.top();pq.pop();
        int dd = -xx.F;
        int nn = xx.S;
        
        if(vis[nn]==1)continue;
        vis[nn] = 1;
        
        for(auto v:g[nn]){
            if(vis[v.F]==0 && dd + v.S < dis[v.F]){
                dis[v.F] = dd + v.S;
                pq.push(v.F);
            }   
        }
    }
    
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    
    vector<int> sc;
    int k;
    cin>>k;
    while(k--){
        int x;
        cin>>x;
        sc.push_back(x);
    }
    dijkstra(sc);
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dis[i]);
        for(auto v:g[i]){
            ans = max(ans, (dis[i] + dis[v.F] + v.S)/2);
        }
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}