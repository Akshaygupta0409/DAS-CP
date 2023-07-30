#include<bits/stdc++.h>
//#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mk make_pair 
#define pb push_back
using namespace std;
//basic setup --------------------------------------------------------------------------------------------------
void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
//declaration of golbal variables and functions --------------------------------------------------------------------------------------------------

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n; // number of nodes
int m; // number of edges
vector<vector<int>> g;
vector<int> color;
vector<int> components;
vector<string> s;
using state = pair<int , int>;
int cnt=0;
// helper functions ------------------------------------------------------------------------------------------------


bool valid(int x, int y){
      if(x>=0&&x<n&&y>=0&&y<m)return 1;
      return 0;
}





vector<state> neighbour(state n){
       vector<state> ans;
       for(int i=0; i<4; i++){
            if(valid(n.f+dx[i] , n.s+dy[i])){
                ans.push_back(mk(n.f+dx[i] , n.s+dy[i]));
            }
       }
       return ans;
}



void dfs(state sc){
        s[sc.f][sc.s] = '#';
         for(auto v : neighbour(sc)){
              if(s[v.f][v.s]!='#'){
                dfs(v);
              }
         }
         return;
}



//main logic --------------------------------------------------------------------------------------------------

void solve()
{
    cin>>n>>m;
    s.resize(n); // 1 index;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
             if(s[i][j]=='.'){
                cnt++;
                state st=mk(i,j);
                dfs(st);
             }
        }
     }
     cout << cnt;
    return;
}



//execution of the logic------------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(0);
    setIO();
    int t = 1;
     //cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// explations of code ------------------------------------------------------------------------------------------------
/*




*/