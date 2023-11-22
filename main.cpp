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
#define MP make_pair
#define fa false
#define tr true
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

// main logic 


void solve()
{
    int n , m;
    cin >> n >> m; 
    vector<int> v(n);
    vector<int> pre(n+1 , 1);
    vector<int> suf(n+1 , 1);
    // prefix
    for (int i = 0; i < n; i++)
    {
           cin>>v[i];
           if(i) pre[i] = (pre[i-1]*v[i])%m;
           else pre[i] = v[i];
    }
    //sufix 
    for(int i=n-1; i>=0; i--){
        suf[i] = (suf[i+1]*v[i])%m;
    }
for (int i = 0; i < n; i++)
   {   int a = 1;
       int b = 1;
      a =  (i-1 >= 0  ? pre[i-1] : 1 );
      b =  (i+1<n ? suf[i+1] : 1);
      cout <<( a*b)%m << " ";
   }
   return ;

}


#undef int

int main()
{   
     init_code(); 
     int t=1;
    // cin>>t;
     while(t--)
     {
      solve();
      
      }
       
}