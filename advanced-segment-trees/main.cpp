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
#define fl false
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
int n , m;
int arr[200200];

struct node
{
     int sum;
     // de fault node 
     node( int n=0){
          sum = n;
     }
};

node st[400400];   // naming convention 
node merge(node a ,  node b){
        return node(a.sum + b.sum);
}

void build(int id , int l , int r){
       if(l==r){
           st[id] = node(arr[l]);
           return ;
       }
       int mid = (l+r)/2;
       build(id<<1 , l , mid);
       build(id<<1 | 1 , mid+1 , r);
       st[id] = merge(st[id<<1] , st[(id<<1)|1]);
       return ;
}

void update(int id , int l , int r , int p , int v){
     if(p<l||p>r) return;
     if(l==r){
          st[id] = node(v);
          return ;
     }
     int mid = (l+r)/2;
       update(id<<1 , l , mid,p,v);
       update(id<<1 | 1 , mid+1 , r,p,v);
       st[id] = merge(st[id<<1] , st[(id<<1)|1]);
       return ;
}

node query(int id , int l, int r , int lq , int rq){
       if(l>rq || r<lq) return node(0);
       if(lq<=l && r<=rq){
              return  st[id];
       }
       int mid = (l+r)/2;
       return merge(query(id<<1 , l , mid , lq , rq),query(id<<1 |1 , mid+1 , r , lq , rq ));
}

void solve()
{   
     cin >> n >> m;
     for(int i=0; i<n; i++){ 
           cin >> arr[i];
     }
     build(1 , 0 , n-1);
     while(m--){
          int a , b ,c; 
          cin>>a>>b>>c;
          if(a==2){
               // update
                b--;
                c--;
                node ans = query(1,0,n-1,b,c);
                cout << ans.sum << nl;
             }else{
           // query 
                b--; 
               update(1,0,n-1,b,c);
          }
     }
}

#undef int

int main()
{   
     init_code(); 
     int t=1;
    // cin>>t;
     while(t--)
     {
      solve();
      
      }
}