#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x  // very important line of this template
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

// very importat and crucial idea for this class of problems

// using stack fo next_greater_element time complexity from O(n^3) -> O(n).

/*        
   for array [3 , 1 , 1 , 1 , 2 , 1 , 1 , 1,4 ]
                             __
                          _____
               X       _________
                  _____________           
                               ____
                               ______      Y
                               __________
                               ______________
                       

     no of subarray such that 2 is the maximum in all subarray 
     1. no of elements smaller than 2 in left leys say its x and to right of is lest's say y
     then no of subarray are ( x * y ) because of no fo subarray ending at 2 is  x and no way 
     to entend this subarray i y 


*/

vector<int> data , left , rigth ;
stackM<int> s;


void solve()
{
      int n; 
      cin >> n; 
      data.resize(n);
      left.resize(n);
      right.resize(n;)
    for(int i=0; i<n; i++) cin >>data[i];
    // greater elemtn left to element ;
    for(int i=0; i<n; i++){
        while(!s.empty() && s.top()<data[i]){
            s.pop();
        }
        if(s.empty()) 
    }
      



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
