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
     int n; 
     cin >> n;
     priority_queue<pair<int , int>> pq;
     for(int i=0; i<n; i++){
        int a; cin>>a;
        pq.push(MP(a,i));  
     }
     int j = pq.top().second;
     pq.pop();
     int ans=0;
     while(pq.size()){
         ans = max(ans , pq.top().first*abs(pq.top().first - j));
         pq.pop();
     }
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