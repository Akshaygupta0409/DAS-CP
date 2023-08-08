#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define pb push_back
using namespace std;
// --------------------------------------------------------------------------------------------------
void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//-------------------------------------------------------------------------------------------------------------------------

int n , s;

int ditsum(int n){
   

     int ans = 0;
     while(n>0){
         int temp = n%10;
         ans += temp;
         n = n/10;
     }
     
     return ans;
}

int check(int x){
     if(x-ditsum(x)<s){
        return 1;
     }
     return 0;
}





void solve()
{    cin >> n >> s;
     int lo = 1 , hi = n , ans = 0;

     while(lo<=hi){
        int mid = lo + ((hi-lo))/2;
        if(check(mid)){
           ans = mid;
        lo = mid+1;
       
        }else{
               hi = mid-1;

        }
     }
     cout << n-ans << '\n';
  return;
}



//------------------------------------------------------------------------------------------------
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
