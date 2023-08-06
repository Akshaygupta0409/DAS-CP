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

bool is_bipartite = false;

void dfs(int node , int col){
         vis[node]=1;
         color[node]=col;
         for(auto u : g[node]){
              if(!vis[u]){
                 dfs(u,!col);
              }else{

                  if(color[u]==color[node]){
                     is_bipartite = true;
                  }
              }
         }
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
        g[b].pb(a);
        edgeList.pb(mp(a,b));
        }
        for(int i=1; i<=n; i++){
              if(!vis[i]){
                 dfs(i,0);
              }
        }
     if(is_bipartite){
         cout << "NO\n";
     }else{
        cout << "YES\n";
     }
     //for(auto c : color) cout<< "color of node :" << " " << c << '\n';
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




*/