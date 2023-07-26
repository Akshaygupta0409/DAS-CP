#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[100100];

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    
    // data strurcture for snake.
    int zero_taken = 0;
    
    // setup the pointer.
    int tail = 0;
    int head = -1;
    int ans = 0;
    
    while(tail<n){
        // move head as many elements as possible.
        while(head+1<n && (arr[head+1]==1||zero_taken<k)){
            head++;
            if(arr[head]==0){
                zero_taken++;
            }
        }
        cout<<tail<<" "<<head<<" "<<endl;
        // save the answer.
        ans = max(ans,head-tail+1);
        
        // move tail one step.
        if(tail>head){
            tail++;
            head = tail-1;
        }else{
            if(arr[tail]==0){
                zero_taken--;
            }
            tail++;
        }
    }
    
    cout<<ans<<endl;
}

int main(){
    solve();
}