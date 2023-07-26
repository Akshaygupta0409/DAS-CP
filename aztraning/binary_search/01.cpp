#include<bits/stdc++.h>
#define int long long int 

using namespace std;



void setIO(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif 
   }





int n,k,arr[100100];

int check(int x){
      if(arr[x>=k]){
        return 1;
      }else{
        return 0;
      }
}

void solve(){
      cin>>n>>k;
      // input 
      for(int i=0;i<n;i++){ cin>>arr[i];}
      // implementation of binary search;
      int lo=0; hi=n-1; ans=-1;
      while(lo<=hi){
          int mid = lo+((hi-lo)/2); // to counter overflow
          if(check(mid)){
              ans = mid;
              hi = mid-1;
          }else{
            lo = mid+1;
          }
      }


    return;
}



signed main(){
    setIO();
    int t=1;
    // cin>>t;
    while(t--){
         solve();
     }

    return 0;
}

/*
my understaing of the topic
fistly 
ans variable is very important it ensure that the search space is 
stirctly decreaseing ;

*/