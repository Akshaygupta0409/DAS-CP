
const long long inf = 0x3F3F3F3F3F3F3FLL;
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        long long dis[26][26];
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j)
                {
                    dis[i][i] = 0;
                }
                else
                {
                    dis[i][j] = inf;
                }
            }
        }

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dis[u][v] = min(dis[u][v], (long long)cost[i]);
        }
        // APSP;
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {

                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        long long totalcost = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
            {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                if (dis[u][v] == inf)
                {
                    return -1;
                }
                totalcost += dis[u][v];
            }
        }

        return totalcost;
    }
};