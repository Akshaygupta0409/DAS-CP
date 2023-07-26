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
vector<int> parent;

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
bool cycle_present = false;

void dfs(int node,int par){ // 1 and 2. 
    cout<<node<<endl;
    vis[node]=1; // mark node visited
    parent[node] = par;
    for(auto v:g[node]){ // for all neighbour v of node
        if(!vis[v]){ // if not visited
            dfs(v,node);
        }else{
            // old node, already coloured.
            if(par!=v)
            {
                cycle_present = true;
                // print
                cout<<node<<" "<<v<<endl;
                vector<int> cycle;
                // save the cycle chain you
                int x = node;
                while(x!=v){
                    cycle.push_back(x);
                    x = parent[x];
                }
                cycle.push_back(v);
                
                printer(cycle);
                cout<<endl;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    
    g.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    
    
}

int main(){
    solve();
}





