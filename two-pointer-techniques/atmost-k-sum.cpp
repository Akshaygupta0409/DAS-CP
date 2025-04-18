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




void solve()
{
    int n; int k;
    cin>> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>> v[i];
    }
   // ds required
   int sum = 0;
   int head = -1;
   int tail = 0; 
   int ans = 0;
   while(tail<n){
       while(head+1<n && (sum + v[head+1]) <= k){
             head++;
             sum += v[head];
       }
       ans += (head-tail+1);
       if(tail>head){
           tail++;
           head = tail-1;
       }else{
          sum -= v[tail];
          tail++;
       }
      }
      cout << ans << endl;
 

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