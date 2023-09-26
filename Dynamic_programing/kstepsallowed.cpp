/*

Number of Paths in Grid - 3

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m, you need to find the number of paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). You cannot move more than K consecutive right moves. The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains three space-separated integers n, m, k - the size of the grid and the number of right moves you can make.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the number of paths modulo 10^9 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m, k ≤ 200

0 ≤ aij ≤ 1

It is guaranteed that the sum of nmk over all test cases does not exceed 108.


Sample Input 1

3
3 3 1
0 0 0
0 0 0
0 0 0
3 3 1
0 1 0
0 1 0
0 0 0
2 3 2
0 0 1
0 0 0

Sample Output 1

3
0
2

Note

For the second test case, there is only one path with 2 consecutive right moves, so the answer is 0.

For the third test case, the following 2 paths are possible: (1,1) → (1,2) → (2,2) → (2,3) and (1,1) → (2,1) → (2,2) → (2,3).

*/




#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int grid[201][201];
const int mod = 1e9+7;
int dp[201][201][201];

int rec(int i,int j,int right) {
    //dp(i,j,k)==number of path from (i,j) to (n-1,m-1) and you can move continue k times in right from (i,j)
    if(grid[i][j]==1) return 0;
    
    if(i==n-1 && j==m-1) return 1;
    
    if(dp[i][j][right]!=-1) return dp[i][j][right];
    
    int ans = 0;
    //down
    if(i+1<n && grid[i+1][j]==0)
    ans = (1LL*ans + rec(i+1,j,k))%mod;
    
    //right
    if(j+1<m && right>0 && grid[i][j+1]==0)
    ans = (1LL*ans + rec(i,j+1,right-1))%mod;
    
    return dp[i][j][right] = ans;
}

void solve() {
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            for(int r=0;r<=k;r++) {
                dp[i][j][r] = -1;
            }
        }
    }
    
    cout<<rec(0,0,k)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        solve();
    }
}



// i can learn a lot from this solutions 

#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;
vector<vector<vector<int>>>dp;

int recursive(int n,int m, int k, int i, int j, vector<vector<int>>&vec,int cnt){
    if(i>=n || j>=m || vec[i][j]==1){
        return 0;
    } 
    if(cnt>k){
        return 0;
    }
    if(i==n-1 && j==m-1){
        return 1;
    }

    if(dp[i][j][cnt]!=-1){
        return dp[i][j][cnt];
    }

    int ans = 0;
    (ans += (recursive(n,m,k,i+1,j,vec,0) + recursive(n,m,k,i,j+1,vec,cnt+1))%mod)%mod;
    // cout<<ans<<endl;
    return dp[i][j][cnt] = ans;
}



void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> vec(n,vector<int>(m,0));
    dp.resize(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    cout<<recursive(n,m,k,0,0,vec,0)<<endl;
    dp.clear();
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// // #include <bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int mod = 1e9+7;
// // int n,m,k;
// // int arr[210][210];
// // int dp[210][210][210];
// // int rec(int x, int y, int cnt){
// //     if (cnt>k)return 0;
// //     if (x>=n || y>=m || arr[x][y]==1)return 0;
// //     if (x==n-1 && y==m-1)return 1;
// //     if (dp[x][y][cnt] != -1)return dp[x][y][cnt];
// //     int ans = 0;
// //     ans = (rec(x+1,y,0) + rec(x,y+1,cnt+1))%mod;
// //     return dp[x][y][cnt] = ans;
// // }
// // void solve(){
// //     cin>>n>>m>>k;
// //     for (int i=0;i<n;i++){
// //         for (int j=0;j<m;j++){
// //             cin>>arr[i][j];
// //             for (int l=0;l<=k;l++){
// //                 dp[i][j][l] = -1;
// //             }
// //         }
// //     }
// //     cout<<rec(0,0,0)<<"\n";
// // }
// // signed main(){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);
// //     int T;cin>>T;while (T--)
// //     solve();
// }