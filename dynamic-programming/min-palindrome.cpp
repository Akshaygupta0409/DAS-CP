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
using vpi =vector<pair<long long,long long>>;

void init_code()
{
   fast_io;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif 
}


string s;
int n;
bool vis[1010][1010];
int dp[1010][1010];

int dp_states(int st , int en){
       //
       if(st>=en) return 0;
       //
       int ans = 1e9;
       // transition s
       if(vis[st][en])  return dp[st][en];
       if(s[st]==s[en]){
            ans = min(ans , dp_states(st+1 , en-1));
       }else{
           ans = min(ans , dp_states(st+1,en)+1);
           ans = min(ans , dp_states(st,en-1)+1);
       }

       return dp[st][en]=ans ;
}

void solve()
{

    cin >> s;
    n = s.size();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            vis[i][j] = false;
        }
    }
    cout << dp_states(0,n-1) << nl;

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