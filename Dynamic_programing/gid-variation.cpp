// a bit  problematic code 


#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
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




int n; int m; int k;
int grid[2010][2010];
int Memo[210][210][410];

int dp(int i , int j , int left){
          if(i>=n || j>=m) return 0;
          // base case 
          if(i==n-1&&j==m-1){
               if(left >= 0) return 1;
                return 0;
          }

         
         if(Memo[i][j][k] != -1) return Memo[i][j][k];           
         int ans = 0;
         if(grid[i][j]==1){
            ans += (dp(i,j+1,left-1)%mod + dp(i+1 , j , left-1)%mod)%mod;
          
         }else{
               ans += (dp(i,j+1,left)%mod + dp(i+1 , j , left)%mod)%mod;

         }
         return Memo[i][j][k]=ans%mod;
}        



void solve()
{    
     cin >> n >> m >> k;
     for(int i=0; i<n; i++){
          for(int j=0; j<m;  j++){
                cin>>grid[i][j];
          }
     }
     memset(Memo , -1 , sizeof(Memo));
     cout << dp(0,0,k) << endl;


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