#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[100100];

int check(int x){
    int num_painter = 0;
    int last_painter_time_left = 0;
    
    for(int i=0;i<n;i++){
        // if unsufficient time left for the last painter to continue 
        // painting even this wall after the last one... 
        if(last_painter_time_left<arr[i]){
            // spawn a new painter.
            num_painter++;
            if(num_painter>k){
                // if exceed the limit of k painter, return not possible.
                return 0;
            }
            last_painter_time_left = x;
        }
        // use the current painter's time to paint this wall.
        last_painter_time_left -= arr[i];
    }
    return 1;
}

void solve(){
    cin>>n>>k;
    
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    
    int lo = *max_element(arr,arr+n);
    int hi = sum;
    int ans = hi; // default value
    
    while(lo<=hi){
        int mid = (lo + (hi-lo)/2);
        // cout<<mid<<" "<<check(mid)<<endl;
        if(check(mid)==0){
            lo = mid+1;
        }else{
            ans = mid;
            hi = mid-1;
        }
    }
    
    cout<<ans<<endl;
}

int main(){
    solve();
}


/*
 answer varibale ensures that the search space is stricly decreasing 

 ans = think before declarein default value
 
general complexity o(o(check)*log(hi - iow))


*/
        