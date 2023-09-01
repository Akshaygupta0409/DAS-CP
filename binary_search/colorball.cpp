#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
//#define mp make_pair 
#define pb push_back
using namespace std;

void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , k; 
map<int,int> mp;

bool check(int x,int sum){
    if(mp.size()>=x && sum>=k*x){
        return true;
    }
    return false;
}

void solve()
{  cin >> n >> k;
    for(int i=0; i<n; i++){
          int x; cin>>x;
          mp[x]++;
    }
    int sum = 0;
     for(auto it : mp){
          
           sum += it.s;
     }
   

    int lo=0  , hi=n ,  ans=0;

    while(lo<=hi){
        int mid = lo + ((hi-lo)/2);
        if(check(mid,sum)){
           ans = mid;
           lo = mid+1;
        }else{
            hi = mid-1;

        }
    }
    
   cout << ans << '\n';
   mp.clear();
  return;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(0);
    setIO();
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
