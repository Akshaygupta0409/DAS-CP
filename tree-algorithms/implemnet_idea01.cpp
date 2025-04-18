class Solution
{
public:
    vector<vector<int>> adj;

    const long long INF = 1e18 + 10;
    long long dfs(int c, int p, const vector<int> &a)
    {
        long long ans = a[c] ? a[c] : INF;
        long long x = 0;
        bool b = 0;
        for (int nxt : adj[c])
            if (nxt != p)
            {
                x += dfs(nxt, c, a);
                b = 1;
            }
        if (!b)
            return ans;

        return min(ans, x);
    }
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values)
    {
        int n = values.size();
        adj.clear();
        adj.resize(n);
        for (auto v : edges)
        { 
            int a = v[0], b = v[1];
            adj[a].push_back(b), adj[b].push_back(a);
        }

        long long ans = 0;
        for (int x : values)
            ans += x;
        // cout << ans << endl;
        return ans - dfs(0, -1, values);
    }
};