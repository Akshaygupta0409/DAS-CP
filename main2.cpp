#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define nl '\n'
#define inf 1e18
#define F first
#define S second

const int mod = 1e9 + 7;

int n, m, k;
vector<int> a, b;
int dp[2][1000010];

struct monotone_deque{
    deque<int> dq;
    void insert(int x){
        while((!dq.empty()) && (dq.back() > x)){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if((!dq.empty()) && (dq.front() == x)){
            dq.pop_front();
        }
    }
    int getmin(){
        if(!dq.empty()){
            return dq.front();
        }
        else{
            return 0;
        }
    }
};
// int rec(int level, int left){ // min cost from to reach level .
//     if(level == 0){
//         return 0;
//     }
//     if(dp[level][left] != -1){
//         return dp[level][left];
//     }
//     int ans = rec(level-1, left) + a[level-1];
//     if(left < m){
//         for(int i=min(level, k); i>=1; i--){
//             ans = min(rec(level-i,left+1) + b[level-i] + b[level], ans);
//         }
//     }
//     return dp[level][left] = ans;
// }
void solve(){
    cin>>n>>m>>k;
    a.resize(n);
    b.resize(n);
    // memset(dp,-1,sizeof(dp));
    monotone_deque mt;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    for(int left = m; left >= 0; left--){
        for(int level = 0; level <n; level++){
            if(level == 0){
                dp[left&1][level] = 0;
                continue;
            }
            int ans = dp[left&1][level-1] + a[level-1];
            if(left < m){
                mt.insert(dp[(left+1)&1][level-1] + b[level-1]);
                if(level > k){
                    mt.remove(dp[(left+1)&1][level-k-1] + b[level-k-1]);
                }
                ans = min(ans, mt.getmin() + b[level]);
                // for(int i=min(level, k); i>=1; i--){
                //     ans = min((dp[(left+1)&1][level-i]) + b[level-i] + b[level], ans);
                // }
            }
            
            dp[left&1][level] = ans;
        }
    }
    cout<<dp[0][n-1]<<nl;
    // cout<<rec(n-1, 0)<<nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}



// another  solution for the travel solution  


#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vvi vector<vi>

int n, m, k;
vi a, b;
// vvi dp;

// int rec(int i, int left)
// {
//   // basecase
//   if (i==n-1) return 0;
//   int &ans = dp[i][left];
//   if (ans != -1) return ans;

//   ans = a[i] + rec(i+1, left);
//   if (left > 0)
//   {
//     rep(j,i+1,min(n-1, i+k+1)) ans = min(ans, rec(j, left-1) + b[i] + b[j]);
//   }
//   return ans;
// }

struct monotonic_queue
{
  deque<int> dq;
  void insert(int x)
  {
    while (!dq.empty() and dq.back() > x) dq.pop_back();
    dq.push_back(x);
  }
  void remove (int x)
  {
    if (!dq.empty() and dq.front() == x) dq.pop_front();
  }
  int get_min()
  {
    if (!dq.empty()) return dq.front();
    return 0;
  }
};

void solve()
{
  cin >> n >> m >> k;
  a.assign(n,0); b.assign(n,0);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  vvi dp(m+1, vi(n));

  for (int left=0; left<=m; left++)
  {
    monotonic_queue dq;
    for (int i=n-1; i>=0; i--)
    {
      if (i==n-1) 
      {
        dp[left][i] = 0;
        if (left>0) dq.insert(dp[left-1][i] + b[i]);
      }
      else
      {
        int ans = a[i] + dp[left][i+1];
        if (left > 0)
        {
          if (i < n-k-1) dq.remove(dp[left-1][i+k+1] + b[i+k+1]); 
          // rep(j,i+1,min(n, i+k+1)) ans = min(ans, dp[left-1][j] + b[i] + b[j]);
          ans = min(ans, dq.get_min() + b[i]);
          dq.insert(dp[left-1][i] + b[i]);
        }
        dp[left][i] = ans;
      }
    }
  }
  cout << dp[m][0] << '\n';
}

int32_t main()
{
  int t; cin >> t; while (t--)
  solve();
}




