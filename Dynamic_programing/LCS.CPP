
#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define pb push_back
using namespace std;

void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[1001][1001];
string a ,b;
int n , m;

int rec(int i , int j){
    if(i==n || j==m){
        return 0;
    }
      if(dp[i][j]!=-1)return dp[i][j];

    int ans = 0;
    if(a[i]==b[j]){
        ans = max(ans , 1+rec(i+1,j+1));
    }
    rec(i+1,j); rec(i,j+1);
    return dp[i][j]= ans;
}


void solve()
{    
    cin>>a>>b;
    n = a.size(); m = b.size(); memset(dp , -1 , sizeof(dp));
    int best = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            best= max(best,rec(i,j));
        }
    }
    
    cout << best <<'\n';
  return;
}




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
