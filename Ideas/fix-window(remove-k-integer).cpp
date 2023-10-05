/*

Description

Given an array N integers in nondecreasing order. Remove K integers such that the maximum difference between two consecutive elements is minimized.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two integers N and K, 3<=N<=3*10^5, 1<=K<=N-2.

The second line of each test case contains N space-separated integers, -1e9<=A[I]<=1e9.


Output Format

For each test case print a single integer, representing the minimum-maximum difference between two consecutive elements after removing K integers in a new line.


Sample Input 1

2
5 1
1 5 6 8 9
5 2
1 5 6 7 1000

Sample Output 1

2
1

Note

For the first test case → remove 1.

For the second test case → remove 1 and 1000.
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




void solve()
{

  int n; 
  int k;
  cin >> n>>k;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin>>v[i];
  vector<int> diff;
  for(int i=1; i<n; i++) diff.pb(v[i]-v[i-1]);
  int i=0;
  multiset<int> ms;
  int window = n-k-1;
  for(i=0; i<window; i++){
     ms.insert(diff[i]);
}
int ans = 1e9;
ans = min(ans , (int)*ms.rbegin());
for(int j=window; j<n-1; j++){
       ms.insert(diff[j]);
       ms.erase(ms.find(diff[j-window]));
       ans = min(ans , (int)*ms.rbegin());
}
cout << ans << endl;


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

/*

how sliding window is used to have n-k elemenst and then we 
slid this window to explore every possiblity of taking elemtns form front and back ;

*/