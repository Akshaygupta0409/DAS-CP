#include<bits/stdc++.h>
using namespace std;

// print the  vector 
void printer(vector<int> mp){
    cout<<"(";
    for(auto v:mp){
        cout<<v<<",";
    }
    cout<<")";
}

void printer(map<int,vector<int>> mp){
    cout<<"{";
    for(auto v:mp){
        cout<<"("<<v.first<<", ";
        printer(v.second);
        cout<<" ),";
    }
    cout<<"}\n";
}

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    // [1 , -1, 0, 1, -1, 1, -1]
    
    // prefix sum array.
    int p[n];
    for(int i=0;i<n;i++){
        p[i] = arr[i];
        if(i)p[i]+=p[i-1];
    }
    //0 [1 , 0 , 0 , 1, 0, 1, 0]
    
    long long ans = 0;
    map<int,vector<int>> mp; // mp[x] -> where have we seen prefix[y] = x (a vector)
    mp[0].push_back(-1);
    
    for(int j=0;j<n;j++){
        // p[j]-x = p[y]
        ans += mp[p[j]-x].size();
        cout<<"Needed "<<p[j]-x<<endl;
        printer(mp[p[j]-x]);cout<<"\n";
        
        for(auto st:mp[p[j]-x]){
            cout<<"Found in subarray from "<<st+1<<" to "<<j<<endl; 
        }
        
        mp[p[j]].push_back(j);
        printer(mp);
    }
    cout<<ans<<endl;
}