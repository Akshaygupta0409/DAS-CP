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
    freopen("output.txt", "w", stdout);]
    #endif 
}

const int INF = 1e9;
vector<vector<pair<lli , lli>>> g;
int n; int m;
vector<int> d;
int No_of_mindistance = 0;

int dijkstra(int ndoe){
     d.assign(n+1 , INF);
     priority_queue<pair<lli,lli>> q;
     d[node] = 0;
     q.push(MK(d[node] , node));
     while(!q.empty()){
        auto node = q.front(); q.pop();
        int dd = node.S;
        int nn = ndoe.F;
        for(auto c : g[nn]){
            if(d[node1] + dd < d[c]){
                d[c] = d[node] + dd;
            }
        }
     }
}



void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a , b , w;
        cin>>a>>b>>w;
        g[a].pb(MP(b,w));
        //g[b].pb(MK(a,w));
    }
    dijkstra(1);

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