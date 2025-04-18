/*
Distinct Integers

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array A of N integers and an integer K, a subarray of A is good if the number of distinct integers present in the subarray is exactly K. Find the number of good subarrays.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100000).

The first line of each test case contains two space-separated integers N, K (1<=N<=100000), (1<=K<=10^6).

The second line contains N space-separated integers A1,A2,…,AN, (0<=Ai<=10^6).

Sum of N overall test case <=10^6.


Output Format

For each test case output in a new line the number of good subarrays.


Sample Input 1

5
5 2
1 2 3 4 5
6 3
1 2 3 2 4 2
10 4
1 2 2 3 2 4 1 3 1 2
10 5
1 2 3 4 1 2 3 4 1 2
10 5
1 2 3 4 1 5 2 5 2 6 

Sample Output 1

4
6
21
0
12
 


Note

For the 1st test case, good subarrays are - {1,2},{2,3},{3,4},{4,5}

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


// best and write way 

void solve()
{
   int n; 
   int k;
   cin >> n >> k;
   vector<int> v(n);
   v.clear();

   for(int i=0; i<n; i++) 
         cin>>v[i];
   //
   map<int,int> mp;
    int head = -1;
    int tail= 0;
    int ans = 0;
    while(tail<n){
         while(head+1<n && ((mp.find(v[head+1])==mp.end()?1:0) + mp.size()) <= k ){
             head++;
             mp[v[head]]++;
         }
         ans += (head-tail+1);
         if(tail>head){
           tail++;
           head = tail - 1;
         }else{
             mp[v[tail]]--;
             if(mp[v[tail]]==0){
                  mp.erase(v[tail]);
             }
             tail++;
              
         }
 
          
    }


    

  mp.clear();
  head = -1;
  tail = 0;
  int ans2 = 0;

   while(tail<n){
         while(head+1<n && ((mp.find(v[head+1])==mp.end()?1:0) + mp.size()) <= (k-1) ){
             head++;
             mp[v[head]]++;
         }
         ans2 += (head-tail+1);
         if(tail>head){
           tail++;
           head = tail - 1;
         }else{
             mp[v[tail]]--;
             if(mp[v[tail]]==0){
                  mp.erase(v[tail]);
             }
             tail++;
              
         }
 
          
    }

   cout << ans - ans2 << endl;
   v.clear();
   mp.clear();
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

Exactly k =( no of subarray at most k )- (no of subarray at most k-1);

*/