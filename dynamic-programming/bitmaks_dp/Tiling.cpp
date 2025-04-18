#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int dp[12][12][(1LL<<12)];

int func(int i, int j, int mask){
    if(i == n){
        // If we have filled all rows and the mask is full, we have a valid tiling
        return (mask == 0) ? 1 : 0;
    }
    if(j == m) {
        // Move to the next row if we have processed the current row
        return func(i + 1, 0, mask);
    }
    if(dp[i][j][mask] != -1) return dp[i][j][mask];
    
    int ans = 0;
    
    // If current cell is already filled
    if(mask & (1LL << j)) {
        ans = func(i, j + 1, mask ^ (1LL << j)); // Move to the next column
    } else {
        // Place a vertical domino
        if(j + 1 < m && !(mask & (1LL << (j + 1)))) {
            ans += func(i, j + 2, mask);
        }
        // Place a horizontal domino
        if(i + 1 < n) {
            ans += func(i, j + 1, mask | (1LL << j));
        }
    }
    
    return dp[i][j][mask] = ans;
}

void solve(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, 0) << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




/*

Tiling

Hard

Difficulty

5 sec

Time Limit

256000KB

Memory

100

Score
Description

Find the number of ways to Tile NxM rectangle with dominoes. A domino is 2 * 1 or 1 * 2 rectangle.
Input Format

The first line contains an integer T (1 ≤ T ≤ 100) - the number of testcases.

The first line of each test case contains two space-separated integers N, M. 1 ≤ N, M ≤ 12.
Output Format
Constraints
Sample Input 1
7
10 3
10 5
2 3
10 1
2 4
5 4
9 11
Sample Output 1
571
185921
3
1
5
95
0



*/