/*

Max Score Possible

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Given an array of N integers. Suppose you chose two index i, j. Score(i,j) is min(A[i],A[j])*abs(i-j). Print the maximum possible score among all the pairs(i,j) (1 ≤ i, j ≤ N). For example, if A = [1,2,3,4,4,5], the maximum score is between the third and sixth index. Here score = min(3, 5) * 3 = 9 units.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, 1≤N≤10^5.

The next line contains N space-separated integers, 1 ≤ A[i] ≤ 10^6.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the max score possible in a new line.


Sample Input 1

2
4
531925 419013 483258 219954 
5
1 4 5 7 8

Sample Output 1

966516
12


*/


#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define nl '\n'
#define F first
#define S second
#define MP make_pair
#define fa false
#define tr true
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

// main logic 


void solve()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
          cin >> v[i];
    }
    int l=0 , r=n-1;
    int ans = 0;
    while(l<=r){
        ans = max(ans , min(v[l],v[r])*abs(l-r));
        if(v[l]<v[r]){
           l++;
        }else{
           r--;
        }
    }

    cout << ans << nl;

return ;


}


#undef int

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