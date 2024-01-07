#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define nl '\n'
#define F first
#define S second
#define MP make_pair
#define ins insert
#define str string
#define r resize
#define agn assign

using lli = long long int;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using vs = vector<str>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

static const int mod = 1e9+7;

int m , dd;
string l  , r;
int digitdp[2010][2][2][2010];
bool vis[2010][2][2][2010];


int dp(int p , int tlo , int thi , int number){
        // base case 
        if(p==l.length()){
            return (number==0 ? 1 : 0);
        }
        int lo=0;
        int hi=9;
        if(tlo){
            lo = l[p]-'0';
        }
        if(thi){
            hi = r[p]-'0';
        } 
        int ans = 0;
        for(int d=lo; d<=hi; d++){
            int ntlo = tlo;
            int nthi = thi;
            if(d!=l[p]) ntlo = 0;
            if(d!=r[p]) nthi = 0;
            if(p%2==0) d = dd;
            ans += dp(p+1,ntlo,nthi,(number*10 + d)%m);
            ans %= mod;
        }


       return ans;
}

void solve()
{
    cin >> m >> dd;
    cin >> l >> r;
    memset(vis , false , sizeof(vis));
    cout << dp(0,1,1,0) << nl;
    return;
}


int main()
{
    fast_io;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}