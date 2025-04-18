#include<bits/stdc++.h>
using namespace std;

#define MP make_pair

int n,m;
int arr[1001][1001];

bool done[1001][1001];
pair<int,int> dp[1001][1001];



pair<int,int> rec(int x,int y){ //  min cost to reach (x,y) from (0,0), # of such path
    // pruning
    if(x<0 || x>n || y<0 || y>m) return MP(1e9,0);
    // basecase
    if(x==0 && y==0) {
        return MP(arr[0][0],1);
    }
    // cache check
    if(done[x][y]) return dp[x][y];

    // transition
    pair<int,int> ans = MP(1e9,0);
    pair<int,int> temp1 = rec(x-1,y);
    pair<int,int> temp2 = rec(x,y-1);

    if(temp1.first == temp2.first){
        ans.first = temp1.first + arr[x][y];
        ans.second = temp1.second + temp2.second;
    }
    else if(temp1.first < temp2.first){
        ans.first = temp1.first + arr[x][y];
        ans.second = temp1.second;
    }
    else{
        ans.first = temp2.first + arr[x][y];
        ans.second = temp2.second;
    }
    
    // save and return
    dp[x][y] = ans; 
    done[x][y] = true;
    return ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    // clearing the DP table.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            done[i][j] = false;
        }
    }
    
    auto ans = rec(n,m);
    cout<<ans.first<<" "<<ans.second<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}