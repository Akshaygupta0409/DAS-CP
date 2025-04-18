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
#define MK make_pair
using namespace std;
using ii= pair<long long,long long>;
// using lli = long long int ;
using vi= vector<long long>;
using vv= vector<vector<long long>>;
using vpi=vector<pair<long long,long long>>;

void init_code()
{
   fast_io;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif 
}

int n ,m ,k;

int dpmemo[2005][2005];
bool vis[2005][2005];

int dp(int pos , int  mov){
      
      // pruning
      if(mov<0) return 0;
      // base case 
      if(pos==n){
           if(mov==0) return 1;
          return 0;
     } 
        if(vis[pos][mov]) return dpmemo[pos][mov];

      int ans = 0;
      //
      ans = (ans+((m-1)*dp(pos+1 , mov-1))%mod)%mod;
      //
      ans = (ans + dp(pos+1 , mov))%mod;
    
      vis[pos][mov]= true;
      return dpmemo[pos][mov]= ans;
}

void solve()
{   
     cin>>n>>m>>k;
     
     // bricks coloring 
     int ans = 0;
      ans = (m*dp(1,k))%mod;
     cout << ans << nl;

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

// set the global variables with some it is very important to set golabel arrays otherwise it will give you
woring answer