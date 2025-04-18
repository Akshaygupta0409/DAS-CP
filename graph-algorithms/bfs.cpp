#include<bits/stdc++.h>
using namespace std;
/*
7 7
1 2
2 3 
4 5
3 5
1 6
6 4
1 3
*/

void printer(vector<int> v){
    cout<<"[ ";
    for(auto x:v){
        cout<<x<<",";
    }
    cout<<"] ";
}
void printer(vector<vector<int>> v){
    cout<<"[ ";
    for(auto x:v)printer(x);
    cout<<"] ";
}

const int INF = 1e9;

int n,m;
vector<vector<int>> g;


vector<int> vis;
vector<int> dis;

void bfs(int sc){ // O(N+M)
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    
    queue<int> q;
    
    // mark visited and push in queue to explore neighbours.
    vis[sc] = 1;
    dis[sc] = 0;
    q.push(sc);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto v:g[node]){
            if(!vis[v]){
                vis[v] = 1;
                dis[v] = dis[node]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int sc;
    cin>>sc;
    bfs(sc); 
    
    printer(g);
    cout<<endl;
    
    printer(vis);
    cout<<endl;
    
    printer(dis);
    cout<<endl;
}

int main(){
    solve();
}