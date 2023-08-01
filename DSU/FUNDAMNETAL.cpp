#include<bits/stdc++.h>
// #define int long long int
#define f first
#define s second 
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
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


int n; 
int q; 
vector<int> par;
vector<int> rankk;
//vector<pair<int,int>> qurey;

// helper definitions ---------------------------------------------------------------------------------------
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
      
        return 1;
      }
      return 0;
}

//main logic --------------------------------------------------------------------------------------------------

void solve()
{    cin >> n >>q;
     par.resize(n);
     rankk.resize(n);

      for(int i=0; i<n; i++){
         par[i]=i;
         rankk[i]=0;
      }
     while(q--){
        int a,b,c;
         cin>>a>>b>>c;
         if(a==0){
            unite(b,c);
         }else{
            //cout << par[b] << " " <<par[c] << endl;
            cout<<check(b,c)?1:0;
            cout<<'\n';
         }
     }
    //for(auto it : par) cout <<it<< " ";
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