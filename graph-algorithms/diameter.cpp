int ans = 0;
void dfs(int a, int p, vector<vector<int>>& adj, vector<pii>& dp){
    pii& pa = dp[a];  

    for(auto x: adj[a]){
        if(x != p){
            dfs(x, a, adj, dp);
            if(dp[x].X + 1 >= pa.X){
                pa.Y = pa.X;
                pa.X = dp[x].X + 1;
            }
            else if(dp[x].X + 1 > pa.Y){
                pa.Y = dp[x].X + 1;
            }
        }
    }
    ans = max(ans, pa.X + pa.Y);
}