#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lld = long double;
using ull = unsigned long long;      
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lloop(i,k,n) for(ll i = k; i < n;i++)
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define res resize
#define ass assign

#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())
#define len(x) ((int)x.length())
#define all(x) begin(x), end(x)
#define rev(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto& a : x)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define FOR(i, n) for (int i = 0; i < n; i++) 
#define FOR1(i, n) for (int i = 1; i <= n; i++) 
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define sum(x) accumulate(x.begin(), x.end(), 0LL)

#define UNIQUE(X) X.erase(unique(all(X)),X.end())
const ll INF = 1e18;
const ll mxINF = 0x3f3f3f3f3f3f3f3f;
const int intinf = 1e9;
const int mininf = -1e9;

// preprocessing 
int par[100010][21];
int depth[100100];

// build with these
void dfs(int node , int par , int dep){
       par[node][0] = par;
       depth[node]  = dep;
       for(int i=1; i<=19; i++){
          par[node][i] = par[par[node][i-1]][i-1];
       }
       // child of this node;
       for(auto child : g[node]){
        if(node != par){
            dfs(child , node , dep+1);
        }
       }
       return ;
}
// logic of calculating lcA
 int lca(int u , int v){
        if(depth[u] < depth[v]){
            swap(u ,v);
        }
        // jump uptill node u and node v are not at same depth;
        for(int i=19; i>=0; i--){
             if((depth[u] - depth[v])&(1<<i)){
                 u = par[u][i];
             }
        }
        if(u==v) return u;
        // if they are not equal
        for(int i=19; i>=0; i--){
             if(par[u][i] != par[v][i]){
                 u = par[u][i];
                 v = par[v][i];
             }
        }
        // imediate parent of node u;
        return par[u][0];

 }



void solve(){

}

signed main()
{
    fastio();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}