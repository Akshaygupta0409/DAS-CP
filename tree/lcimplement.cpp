using lli = long long;
struct SubtreeVal
{
    multiset<lli> pos;
    multiset<lli> neg;
    void add(lli x)
    {
        if (x >= 0)
        {
            pos.insert(x);
            if (pos.size() > 3)
            {
                pos.erase(pos.begin());
            }
        }
        else
        {
            x = -x;
            neg.insert(x);
            if (neg.size() > 2)
            {
                neg.erase(neg.begin());
            }
        }
    }
    lli getans()
    {
        lli ans = 0;
        if (pos.size() == 3)
        {
            lli temp = 1;
            for (auto v : pos)
            {
                temp *= v;
            }
            ans = max(ans, temp);
        }
        if (pos.size() >= 1 && neg.size() >= 2)
        {
            lli temp = 1;
            for (auto v : neg)
            {
                temp *= v;
            }
            temp *= *pos.rbegin();
            ans = max(ans, temp);
        }
        return ans;
    }
};

class Solution
{
public:
    int n;
    vector<int> sz;
    vector<lli> ans;
    vector<vector<int>> graph;

    SubtreeVal dfs(int nn, int pp, vector<int> &cost)
    {
        SubtreeVal temp;
        temp.add(cost[nn]);
        sz[nn] = 1;
        for (auto v : graph[nn])
        {
            if (v != pp)
            {
                SubtreeVal ch = dfs(v, nn, cost);
                sz[nn] += sz[v];
                for (auto v : ch.pos)
                {
                    temp.add(v);
                }
                for (auto v : ch.neg)
                {
                    temp.add(-v);
                }
            }
        }
        ans[nn] = temp.getans();
        if (sz[nn] < 3)
            ans[nn] = 1;
        return temp;
    }

    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
    {
        n = cost.size();
        sz.resize(n);
        ans.resize(n);
        graph.resize(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(0, -1, cost);

        return ans;
    }
};