/*
    justpay find the largest sum cycle in a directed graph 
*/


#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define F first
#define S second
#define MK make_pair
using namespace std;
using ii= pair<long long,long long>;
// using lli = long long int ;
using vi= vector<long long>;
using vv= vector<vector<long long>>;
using vpi =vector<pair<long long,long long>>;

void init_code()
{
   fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


int n; 

vector<vector<int>> g;
vector<int> col;
vector<int> path_sum;

const int INF = 1000009;
bool cycle_present = false;
int ans =  -INF;

// functional graph concept is used in this quesiton 

void dfs(int node , int curr_sum){
        col[node]=2;
        path_sum[node] = curr_sum;
        for(auto v : g[node]){
             if(col[v]==1){
                dfs(v,curr_sum+v);
             }else if(col[v]==col[node]){
                cycle_present = true;
                 ans = max(ans , path_sum[node]-path_sum[v]+v);
             }
        }
        col[node]=3;

        return ;
}
  // thsi quesiton is base on functional graph i mean  i can still formulate it with some sort of graph algorithm;





void solve()

{   
    
    cin>>n;
    col.assign(n, 1);
    g.resize(n);
    path_sum.resize(n);
    for(int i=0; i<n; i++){
      int x; 
      cin>>x;
      if(x!=-1){
         g[i].pb(x);
      } 
   }
   for(int i=0; i<n; i++){
       if(col[i]==1){
          dfs(i,i);
       }
   }

cout << (cycle_present ? ans : -1) << endl;

}


int main()
{   
    init_code(); 
    int t=1;
    cin>>t;
    while(t--)
    {
     solve();
     
     }
      
}