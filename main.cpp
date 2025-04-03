#include<bits/stdc++.h>
using namespace std;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

map<pair<int,int> , int > ids;
// Breadth First search for finding the min distance
int bfs(int bitmask, int &W,int &H, int &N) {
    int dist[W][H];
    memset(dist, -1, sizeof (dist));

    int maxDist = 0;
    queue<pair<int,int>> Q;

    // all positions with 0 distance
    // i.e. positions with office are pushed in the queue
    for(int i = 0; i < W; i++)
        for(int j = 0; j < H; j++)
            if((bitmask&(1<<ids[make_pair(i,j)]))) {
                dist[i][j] = 0;
                Q.push({i, j});
            }

    assert(Q.size() == N);

    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        maxDist = max(maxDist, dist[x][y]);
        Q.pop();

        // traversing in all four direction
        for(int d = 0; d < 4; d++) {
            int newx = x + dx[d];
            int newy = y + dy[d];

            // if out of grid then not considere
            if(newx >= W || newy >= H || newx < 0 || newy < 0)
                continue;

            // if not computed then updating
            // the min distance
            if(dist[newx][newy] == -1) {
                dist[newx][newy] = dist[x][y] + 1;
                Q.push({newx, newy});
            }
        }
    }

    return maxDist;
}

map<pair<int,int>, int> dp;

// Recursive function used to find the min distance
int solve(int bitmask, int left,int &W,int &H,int &N)
{
    // all office are assigned a position
    if(left == 0) {
        // finding min ditance for current positions
        // of the offices
        return bfs(bitmask,W,H,N);
    }

    // if already computed
    if(dp.find({bitmask, left}) != dp.end()) {
        return dp[{bitmask, left}];
    }

    int minDistance = INT_MAX;
    
    int id = 0;
    for(int i = 0; i < W; i++){
              for(int j = 0; j < H; j++){
                      ids[make_pair(i , j)] = id;
                      id++;
           }

    }
    

    // traversing all position where we can setup a office
    for(int i = 0; i < W; i++)
        for(int j = 0; j < H; j++)
        {
            // if not oocupied by another office
            if(!(bitmask&(1<<ids[make_pair(i,j)]))) {

                // Recurisve call
                int val = solve((bitmask|(1<<ids[make_pair(i , j)])), left-1, W , H ,N);
                minDistance = min(minDistance, val);
            }
        }


    return dp[{bitmask, left}] = minDistance;
}

int MinDistance(int W , int H,int N)
{
    // calling solve function
    int ans = solve(0, N, W, H, N);

    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // taking input
    int W,H,N;

    cin>>W >> H >> N;

    // clearing the map
    dp.clear();
    ids.clear();

    // calling the MimdDistance function
    cout << MinDistance(W,H, N) << '\n';

}




























#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class Graph {
public:
    Graph(int vertices) : V(vertices), time(0), disc(vertices, -1), low(vertices, -1), parent(vertices, -1) {
        adj.resize(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findBridges() {
        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }
    }

    void dfs(int u) {
        disc[u] = low[u] = time++;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // If v is not visited
                parent[v] = u;
                dfs(v);

                // Check if the subtree rooted at v has a connection back to one of u's ancestors
                low[u] = std::min(low[u], low[v]);

                // If the lowest vertex reachable from subtree under v is above u in DFS tree, then u-v is a bridge
                if (low[v] > disc[u]) {
                    std::cout << "Bridge found between " << u << " and " << v << std::endl;
                }
            } else if (v != parent[u]) { // Update low value of u for parent function calls.
                low[u] = std::min(low[u], disc[v]);
            }
        }
    }

private:
    int V; // Number of vertices
    int time;
    std::vector<std::vector<int>> adj; // Adjacency list
    std::vector<int> disc, low, parent;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 3);

    g.findBridges();

    return 0;
}
