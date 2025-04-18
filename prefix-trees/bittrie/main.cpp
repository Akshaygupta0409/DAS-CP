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
// node logicn  for bit trei and i should use this when dealing with xor related problems 

struct node{
   node  *child[2];
   int cnt;
   node(){
    child[0] = nullptr;
    child[1] = nullptr;
     cnt = 0;
   }
};

struct bit_trie{
      node *r;   // root node 
      bit_trie(){
        r = new node();
      }
      // to insert the node 
      void insert(int n){
            node *cur = r;
            cur->cnt++;
            for(int i=31; i>=0; i++){
                int x =( (n&(1<<i)) ? 1 : 0);
                if(cur->child[x]==nullptr){
                    cur->child[x] = new node();
                }
                cur = cur->child[x];
                cur->cnt++;
            }
            return ;
      }
};



void solve()
{



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