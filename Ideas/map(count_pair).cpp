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


// my implemtation 


map<int , int > mp;
vector<int> v;
int n;  int k; 

void solve()
{
      cin>>n>>k;
      v.resize(n);
      for(int i=0; i<n; i++){
          int c; cin >> c;
             v[i] = c; 
            mp[c]++;
      }
      int ans = 0;
      for(int i : v){
          int present = i-k
         auto it = mp.find(present);
         if(it != mp.end()){
            // i will write some conditions to work on it 
             ans += map[f];
         }
      }
   cout << ans << endl;

}


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
