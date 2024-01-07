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
    vector<int> v;
    int a;
    while(cin>>a){
        v.push_back(a);
    }

    if (v.empty()) {
        cout << 0 << nl;
        return;
    }
    

   else if(v.size()==2){
          cout << 1 << nl;
          return;  
   }

    else{

         int k = v.back();
    v.pop_back();
    sort(v.begin() , v.end());


    int i=0 , j=v.size()-1 , ans =0;
    while (i+1 != j)
    {    
        if(v[i]+v[j]>k){
            ans++;
            j--;
        }else{
            ans++;
            i++;
            j--;
        }
    }


    if(v[i]+v[j]<=k){
        cout << ans+1 << nl;
    }else{
        cout << ans+2 << nl;
    }

    }
    
    return;
}


#undef int

int main()
{   
    init_code(); 
    int t=1;

    while(t--)
    {
     solve();
     
     }
      
}