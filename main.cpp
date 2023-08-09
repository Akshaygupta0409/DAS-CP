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
int n,m,k;
vector<int> arr,brr;

int check(int x){
     int cnt = 0;
     for(int i=0; i<n; i++){
        cnt += upper_bound(brr.begin(),brr.end(),x-arr[i])-brr.begin();
     }
     

     if(cnt>=k){
        return 1;
     }

     return 0;
}


void solve()
{  
    cin >> n >> m >> k;
    arr.resize(n);
    brr.resize(m);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cin>>brr[i];
    }
    bool is_swaped=false;
    if(n>m){
     // assumption that i am taking in this implentation n is smaller
     swap(n,m);
     swap(arr,brr);
     is_swaped = true;
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin() , brr.end());
    int lo= arr[0]+brr[0] , hi = arr.back()+brr.back() , ans = -1;
    
    while(lo<=hi){
        int mid = lo +( (hi-lo))/2;
        if(check(mid)){
            ans = mid;
           hi = mid-1;
        }else{
          lo = mid+1;
           }
    }

    cout <<  ans  << '\n';

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
