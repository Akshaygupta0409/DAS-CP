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

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i,k,n) for(ll i = k; i < n;i++)
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
const ll INF = 1e18;
const ll mxINF = 0x3f3f3f3f3f3f3f3f;


ll dpcache[20][2][2];
bool vis[20][2][2];
string low , high , cmp;
ll n;

ll dp(int pos , int tlo , int thi){
 
          // base case;
       
         ll ans = 0;
         ll lo = 0;
         ll hi = 9;

       if(tlo) lo = low[pos]-'0';
       if(thi) hi = high[pos]-'0';
       for(int digit = lo ; digit<=hi; digit++){
               if(digit&1){
                
               }
       }
    


    return dpcache[pos][tlo][thi] = ans;

}


void sove(){
    cin>>low>>high>>cmp;
    ll len= high.length() - low.length();
    n = high.length();
    string temp ;
    while (len--)
    {
         temp += '0';

    }
    low = temp + low;
    cout << dp(0,1,1) << nl;

   return ;
}


// got error because of i wrote wrong spelling of main

int main(){
    fast_io();
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}