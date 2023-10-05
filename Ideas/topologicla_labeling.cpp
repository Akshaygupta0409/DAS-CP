#include<bits/stdc++.h>
#define int long long int
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

vector<vector<int>> g;
int n; int m;
vector<int> In_out_degree;
vector<int> ans;

void solve()
{
     cin>>n>>m;
     In_out_degree.assign(n+1 , 0);
     g.resize(n+1 , vector<int>());
     ans.assign(n+1 , 0);
     for(int i=0; i<m; i++){
          int a , b;
          cin>>a>>b;
          g[b].pb(a); 
          In_out_degree[a]++;
     }

     priority_queue<int> pq;
     for(int i=1; i<=n; i++){
           if(In_out_degree[i]==0) pq.push(i); // if In_out_degree is 0 ;
     }
     int label_no  = n; 
     while(!pq.empty()){
           int nn = pq.top();
           pq.pop();
           ans[nn] = label_no;
           label_no--;
           for(int child : g[nn]){
               In_out_degree[child]--;
               if(In_out_degree[child]==0){
                    pq.push(child);
               }
           }
     }

     for (int i=1; i<=n; i++) cout << ans[i] << " ";

}

#undef int 

int main()
{   
     init_code(); 
     int t=1;
     //cin>>t;
     while(t--)
     {
      solve();
      
      }
       
}


// reverse thinking the approach is what helpe me int htis quesitno 