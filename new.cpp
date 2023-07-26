#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mk make_pair 
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
vector<vector<int>> g;
vector<int> color;
vector<int> components;

// helper functions ------------------------------------------------------------------------------------------------





//main logic --------------------------------------------------------------------------------------------------

void solve()
{
    cin>>n>>m;
    g.resize(n+1); // 1 index;
    for(int i=0; i<m; i++){
        int a , b; 
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
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
     cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// explations of code ------------------------------------------------------------------------------------------------
/*




*/