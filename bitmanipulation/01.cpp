#include<bits/stdc++.h>
#define int long long int 

using namespace std;



void setIO(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif 
   }



void solve(){
         int arr[4] = {1,2,3,4};
        for(int mask=0; mask<(1<<4); mask++){
            for(int i=0; i<4; i++){
                if((mask>>i)&1) cout << arr[i] << " ";
            }
            cout<<'\n';
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

