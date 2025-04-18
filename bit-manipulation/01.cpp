#include<bits/stdc++.h>
#define int long long int 

using namespace std;



void setIO(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif 
   }


// for generation of sunset as bits of array -> (if n->5) 1111 and this is 15 which is a number with four bits 
void solve(){
         int arr[4] = {1,2,3,4};
        for(int mask=0; mask<(1<<4); mask++){
            for(int i=0; i<4; i++){
                if((mask>>i)&1) cout << arr[i] << " ";
            } // I KNOW WHY AND HOW IT WORKS 
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

