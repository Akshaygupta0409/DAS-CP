/*

question




*/



#include<bits/stdc++.h>
#define lli long long int
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

string s;
int cache[1010][1010];
int done[1010][1010];

int dp(int l , int d ,  int n){
    if(l==n) return (d==0?1:0);
    if(d<0) return 0;  // here if depth is negative then no point of exploring furthur 
    if(cache[l][d] != -1) return  cache[l][d]; 
    int ans = 0;
    if(s[l]=='(') ans = (ans + dp(l+1,d+1,n))%mod;
    else if(s[l]=='?') ans = (ans + dp(l+1,d+1,n)+dp(l+1,d-1,n))%mod;
    else ans = (ans + dp(l+1,d-1,n))%mod;
    return  cache[l][d]=ans%mod;
}


void solve()
{
   cin >> s;
   memset(cache , -1 , sizeof(cache)); 
   // using this will cause you tle you should instead use loop uptill size of the string .
   memset(done , 0 , sizeof(done));
   cout << dp(0,0,s.length()) << endl;



}


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


/*  
my mistake getting Runtime Error don't know why on onlie judge 


*/
