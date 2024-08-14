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
