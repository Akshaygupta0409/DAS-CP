/*
Path GCD

Time-Limit: 5 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a tree of N nodes and an array A of length N corresponding to the value of the nodes.

You have to answer Q queries. In each query, two nodes are given x, y→ find the gcd of nodes present on the shortest path from x to y.


Input Format

The first line contains an integer T (1 ≤ T ≤ 10000) - the number of test cases.

The second line of each test case contains two space-separated integers N (1 ≤ N ≤ 10^5).

The next line contains N space-separated integers denoting the value of the nodes. (1 ≤ A[i] ≤ 10^6).

The next N-1 lines contain two space-separated integers u, v (1 ≤ u, v ≤ N) denoting there is an undirected edge between node u and node v.

The next line contains an integer Q (1 ≤ Q ≤ 10^5).

The next Q lines contain three space-separated integers x, y (1 ≤ x, y ≤ N).

Sum of N+Q across all test cases ≤ 2*10^6.


Output Format

For each query print the output in a new line.


Sample Input 1

2
5
2 4 5 10 6
1 2
2 3
3 4
4 5
5
1 2
2 5
4 5
3 4
4 5
5
5 10 15 10 10
1 2
2 3
3 4
3 5
10
1 2
1 3
2 4
2 5
3 5
3 4
4 1
4 5
5 1
2 3

Sample Output 1

2
1
2
5
2
5
5
5
5
5
5
5
5
5
5

*/

// logic and code 

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>val;
vector<vector<int>>adj;
vector<int>depth;
vector<vector<int>>par;
vector<vector<int>>dp;
void dfs(int node,int parent,int dep)
{
    par[node][0]=parent;
    depth[node]=dep;
    dp[node][0]=val[node];

    for(int i=1;i<=20;i++)
    {
        par[node][i]=par[par[node][i-1]][i-1];
        dp[node][i]=__gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
    }

    for(auto v:adj[node])
    {
        if(v!=parent)
            dfs(v,node,dep+1);
    }

}

int gcd_query(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);

    int ans=0;
    for(int i=19;i>=0;i--)
    {
        if((depth[u]-depth[v])&(1<<i))
        {
            ans=__gcd(ans,dp[u][i]);
            u=par[u][i];
        }
    }
    if(u==v)
        return __gcd(ans,val[u]);

    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            ans=__gcd(ans,dp[v][i]);
            v=par[v][i];
            ans=__gcd(ans,dp[u][i]);
            u=par[u][i];
        }
    }

    int part1=__gcd(val[u],val[v]);
    int part2=__gcd(part1,val[par[u][0]]);
    return __gcd(part2,ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int  t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        val.resize(n+1);
         adj.clear();
        adj.resize(n+1);
       
        

        depth.resize(n+1);
        par.assign(n+1,vector<int>(24,0));
        dp.assign(n+1,vector<int>(24,0));
       // val[0]=0;
        for(int i=1;i<=n;i++)
            cin>>val[i];

        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0,0);
        int q;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<gcd_query(u,v)<<'\n';
        }
    }
}