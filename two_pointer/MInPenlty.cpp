// compilation erro 

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

map<int,int> mp;
int n , d;
vector<int> arr;

void solve()
{
    cin>>n>>d;
   
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<d; i++){
        mp[arr[i]]++;
    }
    int ans = 1e9;
    ans = min(ans , (int)size(mp)); // this syntax is wrong don't use this kindof suntax
    for(int i=d; i<n; i++){
        mp[arr[i]]++;
        mp[arr[i-d]]--;
        if(mp[arr[i-d]]==0) mp.erase(arr[i-d]);
        ans = min(ans, (int)size(mp));
    }
    cout<<ans<<'\n'; 
    mp.clear();
  

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