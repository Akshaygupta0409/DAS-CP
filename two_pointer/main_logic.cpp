#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[100100];

// data strurcture for snake.
int distinct_count=0;
int mp[1000100];

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    
    // setup the pointer.
    int tail = 0;
    int head = -1;
    int ans = 0;
    
    while(tail<n){
        // move head as many elements as possible.
        while(head+1<n && (mp[arr[head+1]]!=0||distinct_count<k) ){
            head++;
            cout<<"inserting "<<arr[head]<<endl;
            // insert the element in DS
            if(mp[arr[head]]==0)distinct_count++;
            mp[arr[head]]++;
        }// H = O(logn)
        
        // save the answer.
        ans += (head-tail+1); // A = O(1)
        
        // move tail one step.
        if(tail>head){
            tail++;
            head = tail-1;
        }else{
            // change this 
            cout<<"removing "<<arr[tail]<<endl;
            mp[arr[tail]]--;
            if(mp[arr[tail]]==0)distinct_count--;
            // T = O(log(n))
            tail++;
        }
    }
    
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}