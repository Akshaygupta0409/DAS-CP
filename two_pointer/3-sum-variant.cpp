
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int T;
    cin>>T;
    while(T--){
        int n,t;
        cin>>n>>t;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans=1e18;
        for(int j=0;j<n;j++){
            int i=0;
            int k=n-1;
            while(i<j&&j<k){
                int temp=arr[i]+arr[j]+arr[k];
                ans=min(ans,abs(temp-t));
               if(temp==t){
                  
                   break;
               }else if(temp<t){
                   i++;
               }else{
                k--;
               }
            }
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}


// i have evaluated it well now i will not fall short on this 