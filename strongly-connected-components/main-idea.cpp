#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define nl '\n'
#define F first
#define S second
#define MP make_pair
#define t true
#define f false
using namespace std;
using ii= pair<long long,long long>;
// using lli = long long int ;
using vi= vector<long long>;
using vv= vector<vector<long long>>;
using vpi =vector<pair<long long,long long>>;

void init_code()
{
   fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

// main logic 
vector<vector<int>> g , grev;
vector<bool> vis;
vector<int> topo_order;
vector<set<int>> condense_graph;
int curr_scc=0;
vector<int> scc_number;

int n,m;

// topo ordering on originla graph ;
void dfs1(int node){
       
}


void solve()
{
    cin >> n >> m;
    
     g.resize(n+1);
     grev.resize(n+1);
     vis.assign(n+1,f);
     scc_number.assign(n+1 , 0);

    for (int  i = 0; i <m; i++)
    {
          int  a , b;
          cin >> a >> b; 
          g[a].push_back(b);
          grev[b].push_back(a);

    }
    for(int i=1; i<=n; i++){
         if(!vis[i]){
              curr_scc++;
              dfs1(i);
         }
    }
    


}


#undef int

int main()
{   
    init_code(); 
    int t=1;
    cin>>t;
    while(t--)
    {
     solve();
     
     }
      
}