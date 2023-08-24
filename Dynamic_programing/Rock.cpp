#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define pb push_back
using namespace std;
// --------------------------------------------------------------------------------------------------
void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//-------------------------------------------------------------------------------------------------------------------------

vector<vector<int> g;
vector<int> vis,indegre;
int n , m;

void solve()
{    cin>>n>>m;
    g.resize(n+1);
    indegre.resize(n+1);
    for(int i=0; i<n; i++){
        int a , b;
        cin>>a>>b;
        g[a].pb(b);
    }
    
   priority_queue<int> pq;
   ps.push(some_node_which_is_root_node)


  return;
}



//------------------------------------------------------------------------------------------------
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
