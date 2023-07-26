// undefined 
#include<bits/stdc++.h>
using namespace std;

int non_zero = 0;
int mp[10010];

void insert(int x){
    if(mp[x]==0)non_zero++;
    mp[x]++;
    if(mp[x]==0)non_zero--;
}

void erase(int x){
    if(mp[x]==0)non_zero++;
    mp[x]--;
    if(mp[x]==0)non_zero--;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int j=0;j<m;j++){cin>>brr[j];erase(brr[j]);}
    for(int i=0;i<n;i++){
        insert(arr[i]);
        if(i-m>=0){
            erase(arr[i-m]);
        }
        // print the map.
        if(i-m+1>=0){
            // valid subarray
            if(non_zero==0){
                // perfect match at [i-m+1,i]
                cout<<(i-m+1)<<endl;
            }
        }
    }
}

int main(){
    solve();
}


https://azbootcampb5.slack.com/archives/C058JFWBC2G/p1685116939925749

// leetcoe subarray and matrix tyype questios

int non_zero = 0;
map<int,int> mp;

void insert(int x){
    if(mp[x]==0)non_zero++;
    mp[x]++;
    if(mp[x]==0)non_zero--;
}

void erase(int x){
    if(mp[x]==0)non_zero++;
    mp[x]--;
    if(mp[x]==0)non_zero--;
}

void solve(){
    
    int n,m;
    cin>>n>>m;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int j=0;j<m;j++){cin>>brr[j];erase(brr[j]);}
    
    for(int i=0;i<n;i++){
        insert(arr[i]);
        if(i-m>=0){
            erase(arr[i-m]);
        }
        if(i-m+1>=0){
            // valid subarray
            if(non_zero==0){
                // perfect match at [i-m+1,i]
            }
        }
    }
}