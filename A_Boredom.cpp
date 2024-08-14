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


#define int long long int


int n; 
vector<pair<int,int>> a;
int dp[100100];
bool vis[100100];


void solve(){
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int x; 
        cin >> x;
        mp[x]++;
    }
    a.clear();
    for(auto it : mp){
        a.push_back({it.first, it.second});
    }
    sort(a.begin(), a.end());

    memset(dp, 0, sizeof(dp)); // Initialize dp array to 0

    // Iterative DP computation
    for (int i = a.size() - 1; i >= 0; i--) {
        // Always possible to skip the current pair
        dp[i] = (i + 1 < a.size()) ? dp[i + 1] : 0;

        // If the next pair is valid for the condition
        if (i + 1 < a.size() && a[i + 1].first > a[i].first + 1) {
            dp[i] = max(dp[i], (1LL * a[i].first * a[i].second) + ((i + 1 < a.size()) ? dp[i + 1] : 0));
        }

        // If skipping the next pair
        if (i + 2 < a.size()) {
            dp[i] = max(dp[i], (1LL * a[i].first * a[i].second) + dp[i + 2]);
        } else {
            dp[i] = max(dp[i], 1LL * a[i].first * a[i].second);
        }
    }

    // The answer for the whole problem is now stored in dp[0]
    cout << dp[0] << '\n';
}


signed main()
{
    fastio();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


// accepted solution of the quesiton given above ;