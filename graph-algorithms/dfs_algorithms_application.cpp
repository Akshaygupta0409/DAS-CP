#include<bits/stdc++.h>
using namespace std;


/*
8 7
1 2
2 3
1 3
1 4
4 3
7 6
6 8
*/

int n,m;

vector<vector<int>> g;
vector<int> vis;
vector<int> comp_no;

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

// O(N+M)

int cnt = 0;

void dfs(int node){
    vis[node]=1; // mark node visited
    comp_no[node] = cnt;
    for(auto v:g[node]){ // for all neighbour v of node
        if(!vis[v]){ // if not visited
            dfs(v);
        }
    }
}

void solve(){
    cin>>n>>m;
    
    g.resize(n+1);
    vis.resize(n+1);
    comp_no.resize(n+1);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<comp_no[i]<<endl;
    }
    
    cout<<cnt<<endl;
}

int main(){
    solve();
}