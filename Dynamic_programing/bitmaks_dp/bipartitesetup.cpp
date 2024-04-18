int inf = 1e9;
class Solution
{
public:
    int dpcache[101][28][101][101];
    bool vis[101][28][101][101];

    int getLengthOfOptimalCompression(string s, int k)
    {
        for (auto &it : s)
            it -= 'a';
        int n = s.length();
        // dp initialization

        // dp function
        function<int(int, int, int, int)>
            dp = [&](int idx, int pchar, int len, int lft)
        {
            // pruning
            if (lft < 0)
                return inf;
            // base case pruing already handled imppossible branches
            if (idx >= n)
            {
                return 0;
            }

            if (vis[idx][pchar][len][lft])
                return dpcache[idx][pchar][len][lft];
            // transition
            int ans = inf;
            if (pchar == s[idx])
            {
                if (len == 1 || len == 9 || len == 99)
                {
                    ans = min(ans, 1 + dp(idx + 1, pchar, len + 1, lft));
                }
                else
                {
                    ans = min(ans, dp(idx + 1, pchar, len + 1, lft));
                }
            }
            else
            {
                ans = min(ans, 1 + dp(idx + 1, s[idx], 1, lft));
            }

            ans = min(ans, dp(idx + 1, pchar, len, lft - 1));
            vis[idx][pchar][len][lft] = true;
            return dpcache[idx][pchar][len][lft] = ans;
        };
        memset(vis, false, sizeof(vis));
        return dp(0, 26, 0, k);
    }
};