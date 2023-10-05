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
using vi= vector<int>;
using vvi= vector<vector<int>>;
using vpi =vector<pair<int,int>>;

void init_code()
{
   fast_io;
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif 
}

vector<int> v , w;
int n;
int W;
int Memo[101][1000100];

int dp(int idx  , int value){  // minimun weight from [0 .......... i ] to generate the value ;
   // base case ;
      if(idx==n){
           if(value==0) return 0;
           return 1e18;
      }
     
   // precomputatoin check 
   if(Memo[idx][value] != -1) return Memo[idx][value] ;
     
   int ans = 1e18;
   // transitions 
   
   ans = min(dp(idx+1,value), w[idx] + dp(idx+1,value - v[idx]));
   // return 
   return Memo[idx][value] = ans;
             
}

void solve()
{
      cin>>n>>W;
      v.resize(n);
      w.resize(n);
       
       // max value 
        int  maxV = 0;
       
      for(int i=0; i<n; i++){
          cin >> w[i] >> v[i];
          maxV += v[i];
      }
      
      int res = 0;
        
        memset(Memo , -1 , sizeof(Memo));

      for(int i=0; i<=maxV; i++){
             if(dp(0 , i) <= W) res = i ;
           
      }

      cout  << res << endl;


    return ;
}

#undef int



int main()
{   
     init_code(); 
     int t=1;
     //cin>>t;
     while(t--)
     {
      solve();
      
      }
       
}