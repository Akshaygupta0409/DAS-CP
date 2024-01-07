/*
Description
My Submissions
Hints/Editorial
AC Submissions
My Notes (0)
D-Magic Number

Time-Limit: 5 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

A number N is said to be D-Magic if digit D appears in the decimal representation of the number on only even positions. You have to tell the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M. Since the answer can be large, print the number of integers modulo 109 + 7.

It is given that the number of digits in A and B is the same and A ≤ B.

 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers M and D.

The second line of each test case contains one integer A.

The third line of each test case contains one integer B.


Output Format

Print single integer denoting the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M, modulo 109 + 7.


Constraints

1 ≤ T ≤ 5

1 ≤ M ≤ 2000

0 ≤ D ≤ 9

1 ≤ A ≤ B ≤ 102000


Sample Input 1

3
2 4
10
90
3 9
200
300
2 1
10 
90

Sample Output 1

7
3
0

Note

For the first test case, the following are the 12 numbers between 10 and 90 which are 2-Magic Numbers: 14, 24, 34, 54, 64, 74, 84.

For the second test case, the following are the 7 numbers between 200 and 300 which are 9-Magic Numbers: 291, 294, 297.

For the third test case, there are no 1-Magic Numbers between 10 and 90.

*/


#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll len, M, dp[2020][2][2][2000][3], mod = 1e9+7, D;
string L, R;

ll rec(ll level, ll tlo, ll thi, ll rem, ll st){
    if(level == len){
        if(rem == 0) return 1;
        else return 0;
    }
    if(dp[level][tlo][thi][rem][st] != -1) return dp[level][tlo][thi][rem][st];
    
    ll lo = 0, hi = 9;
    if(tlo == 1) lo = L[level]-'0';
    if(thi == 1) hi = R[level]-'0';

    // cout << lo << " aaaaaaa " << hi << " " << st << '\n';
    
    ll ans = 0;
    for(ll i = lo; i <= hi; i++){
        ll ntlo = tlo, nthi = thi, nrem, nst;
        if(i != lo) ntlo = 0;
        if(i != hi) nthi = 0;
        nrem = (10*rem+i)%M;
        
        if(st == 0){
            if(i == 0) nst = 0;
            else nst = 1;
        }else{
            nst = 3-st;
            // cout << "BBBBB " << nst << " CCCC " << level << '\n';
        }
        
        if(i != D && nst == 2){
            // cout << "Hello\n";
            continue;
        }

        if(i == D && nst != 2){
            continue;
        }
        // else if(i == D){
        //     // cout << "Reached\n";
        //     nf = 1;
        // }

        // cout << "level = " << level << " (" << tlo << " " << thi << ") " << " rem = " << rem << " state = " << st << " ans = " << ans << '\n';

        
        ans += rec(level+1, ntlo, nthi, nrem, nst);
        ans %= mod;
    }
    
    
    
    return dp[level][tlo][thi][rem][st] = ans;
}

void solve(){
    cin >> M >> D;
    cin >> L;
    cin >> R;
    len = R.length();
    
    // memset(dp, -1, sizeof(dp));
    for(ll i = 0; i <= len; i++){
        for(ll j = 0; j < 2; j++){
            for(ll k = 0; k < 2; k++){
                for(ll l = 0; l <= M; l++){
                    for(ll m = 0; m < 3; m++){
                        
                            dp[i][j][k][l][m] = -1;
                        
                    }
                }
            }
        }
    }
    
    
    string temp = "";
    ll cnt = R.length()-L.length();
    while(cnt--){
        temp += '0';
    }
    L = temp + L;
    
    cout << rec(0, 1, 1, 0, 0) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;


    while(tc--){
        solve();
    }

    return 0;
}


// another idea for the problem 

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define yes cout<<"Yes"<<endl 
#define no cout<<"No"<<endl 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod2 = 998244353;
const ll mod = 1e9+7;
const int N = 200100;
const int INF = 1e9;

ll m, d, len;
string L, R;

// Returns the number of numbers such that sum of digits in 
// base 10 is a Multiple of m
ll dp[2020][2][2][2020];

// curRem -> remainder till now

ll rec(int level, int tlo, int thi, int curRem){
    if(level == len){
        if(curRem == 0) return 1;
        else return 0;
    }

    if(dp[level][tlo][thi][curRem] != -1){
        return dp[level][tlo][thi][curRem];
    }

    ll ans = 0, l=0, r =9;

    if(tlo){
        l = L[level]-'0';
    }
    if(thi){
        r = R[level]-'0';
    }

    for(int i=l; i<=r; i++){
        if(level%2 == 0 && i == d) continue;
        if(level%2 && i != d) continue;

        int ntlo = 0, nthi = 0;
        if(tlo == 1 && i == l) ntlo = 1;
        if(thi == 1 && i == r) nthi = 1;

        ll newRem = (curRem*10 + i)%m;

        ans = (ans + rec(level+1, ntlo, nthi, newRem))%mod;

    }

    return dp[level][tlo][thi][curRem] = ans%mod;
}

void solve(){
    cin>>m>>d;
    cin>>L>>R;
    len = R.length();

    memset(dp, -1, sizeof(dp));

    cout<<rec(0, 1, 1, 0)<<endl;
}

int main(){
    fast
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

// third style of coding the same question thats good 
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
#define F first
#define S second
#define lli long long int
using ii = pair<lli,lli>;
#define MP make_pair
lli m,d, ans = 0;
string a,b;

lli mod = 1e9+7;

lli dp[2005][2][2][2005];
// vector<vector<vector<vector<lli>>>> dp(2005,vector<vector<vector<lli>>>(2,vector<vector<lli>>(2,vector<lli>(2005,-1))));


lli rec(lli level,lli tlo, lli thi, lli sum){
    if(level==b.length()){
        if(sum==0) return 1;
        else return 0;
    }
    if(dp[level][tlo][thi][sum]!=-1) return dp[level][tlo][thi][sum];
    lli ans = 0;
    lli lo =0;
    if(tlo == 1) lo = a[level]-'0';
    lli hi = 9;
    if(thi == 1) hi = b[level]-'0';
    
    for(lli i=lo;i<=hi;i++){
        lli ntlo = tlo,nthi= thi;
        if(i!=a[level]-'0') ntlo = 0;
        // lli nthi = 0;
        if(i!=b[level]-'0') nthi = 0;
        // if(tlo==1&&i==a[level]-'0')
        // {
        //     ntlo=1;
        // }
        // if(thi==1&&i==b[level]-'0')
        // {
        //     nthi=1;
        // }
        if((level+1)%2){
            if(i!=d) ans = (((ans+ rec(level+1,ntlo,nthi,((sum*10)+ i)%m))%mod)+mod)%mod;
        }
        else{
            if(i==d) ans = (((ans+ rec(level+1,ntlo,nthi,((sum*10)+ i)%m))%mod)+mod)%mod;
        }
    }
    return dp[level][tlo][thi][sum] = ans;
    
    
}

void solve(){
   cin>>m>>d;
   cin>>a>>b;
//   vector<vector<vector<vector<lli>>>> dp(n,vector<vector<vector<lli>>>(2,vector<vector<lli>>(2,vector<lli>(m,-1))));
  memset(dp,-1,sizeof(dp));

   lli cnt = b.length()-a.length();
   
   string temp = "";
   while(cnt--){
       temp+='0';
   }
   a = temp+a;
   cout<<rec(0,1,1,0)<<'\n';
}



signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t;cin>>_t;
    int tt = 1;
    while(_t--){
    //     cout<<"Test case #"<<tt<<'\n';
    //     tt++;
        solve();
    }
    return 0;
}