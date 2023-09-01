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


//-------------------------------------------------------------------------------------------------------------------------

int n , m;
vector<vector<int>> arr;
int dp[1010][1010];

int INF = 1e9+7;

int rec(int i , int j){
      if(i==n-1 && j==m-1){
        return arr[n-1][m-1];
      }
       if(i==n || j==m) return -INF;
       if(dp[i][j]!=-1) return dp[i][j];
       int ans=0;
       ans = max(ans , max(rec(i+1,j) , rec(i,j+1))+arr[i][j]);
       return dp[i][j]= ans;
}

void solve()
{  cin>>n>>m;
   arr.resize(n,vector<int>(m));
    memset(dp , -1 , sizeof(dp));
   
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         cin>>arr[i][j];
      }
   }
   cout<<rec(0,0)<<'\n';
  return;
}



//------------------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(0);
  
    int t = 1;
     cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
