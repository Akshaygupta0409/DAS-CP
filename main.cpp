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
int n , m;
vector<vector<int>> g;
vector<int> vis , color , comp;




void solve()
{  
    cin >> n >> m;
    g.resize(n+1); // 1 indexed;

    for(int i=0; i<m; i++){
         int fr,to;
         cin>> fr>>to;
         g[fr].pb(to);
         g[to].pb(fr);
    }

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
