#include<bits/stdc++.h>
//#define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
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


int n; // number of nodes
int m; // number of edges
int comp_num=0;
vector<pair<int,pair<int,int>>> edgeList;
//vector<vector<pair<int>> g;
vector<int> color;
vector<int> components;
vector<int> vis;
map<int,int> mpp;
vector<int> par;
vector<int> rankk;
// helper functions ------------------------------------------------------------------------------------------------------------



    
    int find(int x){
     if(par[x]==x) return x;
     else{
         return par[x] = find(par[x]);
     }
}

 void unite(int x , int y){
        int xx = find(x);
        int yy = find(y);
        if(rankk[xx]<rankk[yy])swap(xx,yy);
        if(rankk[xx]==rankk[yy])rankk[xx]++;
        par[yy]=xx;
        return;
    } 

int check(int x , int y){
      if(find(x)==find(y)){
      
        return 0;
      }
      return 1;
}







//main logic -------------------------------------------------------------------------------------------------------------------

void solve()
{
    cin>>n>>m;
   // g.resize(n+1); // 1 index;
    components.resize(n+1);
    vis.assign(n+1 , 0);
    color.resize(n+1);
     par.resize(n+1);
     rankk.resize(n+1);


     for(int i=1; i<=n; i++){par[i]=i;}
    for(int i=0; i<m; i++){
        int a , b ,cst; 
        cin>>a>>b>>cst;
        // g[a].pb(b);
        // g[b].pb(a);
        edgeList.pb(mp(cst,mp(a,b)));
        }
        sort(edgeList.begin() , edgeList.end());


        int ans=0;
        int cnt=0;
        for(auto v : edgeList){
             int x = v.s.f;
             int y = v.s.s;
             if(find(x)!=find(y)){
                 cnt++;
                 ans  += v.f;
                 unite(x,y);
             }

        }  
       

       if(cnt==n-1)cout<<cnt<<" "<<ans<<'\n';
       else cout << "IMPOSSIBLE\n";

    return;
}


//execution of the logic------------------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    cout.tie(0);
    setIO();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// explations of code ------------------------------------------------------------------------------------------------
/*




*/