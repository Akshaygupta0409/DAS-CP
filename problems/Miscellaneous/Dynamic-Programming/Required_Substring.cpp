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

// Type definitions
using ll = long long;
using lld = long double;
using ull = unsigned long long;	  
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// Constants
const ll INF = 1e18;
const ll mxINF = 0x3f3f3f3f3f3f3f3f;
const int intinf = 1e9;
const int mininf = -1e9;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double PI = 3.141592653589793238462;

// Macros
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lloop(i,k,n) for(ll i = k; i < n;i++)
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define res resize
#define ass assign
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define len(x) ((int)x.length())
#define all(x) begin(x), end(x)
#define rev(x) reverse(x.begin(), x.end())
#define trav(a, x) for (auto& a : x)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define FOR(i, n) for (int i = 0; i < n; i++) 
#define FOR1(i, n) for (int i = 1; i <= n; i++) 
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define SUM(x) accumulate(x.begin(), x.end(), 0LL)
#define UNIQUE(x) x.erase(unique(all(x)), x.end())

/**
 * Binary exponentiation function.
 * Calculates (base^exp) % MOD efficiently.
 */
ll binary_exp(ll base, ll exp) {
    base %= MOD;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    
    int window_count = n - s.length() + 1; // Number of possible windows
    int remaining_positions = n - s.length(); 
    
    // Calculate total number of possible strings
    ll answer = (window_count * binary_exp(26, remaining_positions)) % MOD;
    cout << answer << nl;
}

int main() {
    fastio();
    int test_cases = 1;
    // Uncomment the line below for multiple test cases
    // cin >> test_cases;
    
    while (test_cases--) {
        solve();
    }
    return 0;
}