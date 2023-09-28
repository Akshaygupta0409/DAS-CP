/*

3 Sum

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum-target) is minimum). Print the minimum absolute value of (sum-target). You cannot select an index more than one. All three indexes should be distinct.


Input Format

The first line contains T, the number of test cases (1<=T<=100).

The first line contains two space-separated integers N, target where 3<=N<=10^3, -1e18<=target<=1e18.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

The Sum of N across all test cases ≤ 10^4.


Output Format

For each test case print the minimum absolute value of (sum-target).


Sample Input 1

1
5 3
1 2 3 4 5

Sample Output 1

3



*/


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
     freopen("output.txt", "w", stdout);
     #endif 
}

// two pointers 3 sum variant and coding sytel 


void solve()
{   
     int n; int t ; cin>>n; cin>>t;
     vector<int> v(n);
     for(int i=0; i<n; i++) cin >> v[i];
     sort(v.begin() , v.end());
     int ans = 1e9;
     for(int j=0; j<n; j++){
           int i=0; 
           int k=n-1;
           while(i<j&&j<k){
               int sum = v[i]+v[j]+v[k];
               if(sum>t){
                    ans = min(ans , sum);
                    k--;
                    
                }else if(sum<t){
                    ans = min(ans,sum);
                    i++;
                }else{
                    if(sum==t) break;
                      
                }
           }
     }

     cout << abs(ans - t) << endl ;

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