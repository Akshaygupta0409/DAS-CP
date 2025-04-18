#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define lloop(i, k, n) for (ll i = k; i < n; i++)
#define mod 1000000007
#define MOD1 998244353
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define res resize
#define ass assign
#define int long long

#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())
#define len(x) ((int)x.length())
#define all(x) begin(x), end(x)
#define rev(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto &a : x)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define sum(x) accumulate(x.begin(), x.end(), 0LL)

#define UNIQUE(X) X.erase(unique(all(X)), X.end())
const ll INF = 1e18;
const ll mxINF = 0x3f3f3f3f3f3f3f3f;
const int intinf = 1e9;
const int mininf = -1e9;

// i though about dp  because it is given that graph does not contian directed edges;

map<int, vi> graph;
int n, m;
int cache[100100];
vector<bool> vis(100100);

int dp(int nn) {
  if (nn == n)
    return 1;
  if (vis[nn])
    return cache[nn];
  int ans = 0;
  for (int c : graph[nn]) {
    ans = (ans % mod + dp(c) % mod) % mod;
  }
  vis[nn] = true;
  return cache[nn]= ans;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
   

  }
  for(int i=0; i<n+10; i++ ) vis[i]=false;
  cout << dp(1) << nl;
  graph.clear();
  vis.clear();
  return;
}

signed main() {
  fastio();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

/*
questoin : 
Complete the Game

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?


Input Format

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1, 2, …, n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.


Output Format

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

4 5
1 2
2 4
1 3
3 4
1 4

Sample Output 1

3





*/