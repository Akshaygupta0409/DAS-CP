#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define pb push_back
using namespace std;
//basic setup --------------------------------------------------------------------------------------------------
void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
//declaration of golbal variables and functions --------------------------------------------------------------------------------------------------
const int INF = 1e18;
const int NINF = -1e18;

int n; // number of nodes
int m; // number of edges
int comp_num=0;
vector<pair<int,int>> edgeList;
vector<vector<int>> g;
vector<int> color;
vector<int> components;
vector<int> vis;
map<int,int> mpp;


// helper functions ------------------------------------------------------------------------------------------------------------

vector<int> toposort;

void dfs(int node){
          vis[node]=1;
        for(auto v : g[node]){
              
               if(!vis[v]){
                 dfs(v);
               }
              }
     
        toposort.pb(node);
        return;
}


//main logic -------------------------------------------------------------------------------------------------------------------

void solve()
{
    cin>>n>>m;
    g.resize(n+1); // 1 index;
    components.resize(n+1);
    vis.assign(n+1 , 0);
    color.resize(n+1);

    for(int i=0; i<m; i++){
        int a , b; 
        cin>>a>>b;
        g[a].pb(b);
        //g[b].pb(a);
        edgeList.pb(mp(a,b));
        }
        for(int i=1; i<=n; i++){
              if(!vis[i]){
                dfs(i);
              }
        }
        reverse(toposort.begin() , toposort.end());
        for(auto v : toposort){
             cout << v << " ";
        }
    return;
}


//execution of the logic------------------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(0);
    setIO();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// explations of code ------------------------------------------------------------------------------------------------
/*
topological sorts are only applicabel in directed acyclic graph




*/