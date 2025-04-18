#include<bits/stdc++.h>
#define all(x) ((x).begin() , (x).end())
using namespace std;

// main logic 
// give a array of n size you have to answer quereies of type 
// L  R   give number of element < k 

struct N{
    vector<int> vals;

};
// always make array of size 
N t[400400];


// most important property of segment tree is that ki every range decomposes to exactly log n disjoint nodes of so now what tod 


/*
                                   [--------------------]

     [                                                  ]

     [                    ]  [                          ]

     [         ][           ]









*/                 

N merge(N a , N b){
    N ans;
    for(int i=0; i<a.vals.size(); i++) ans.vals.push_back(a.vals[i]);
    for(int i=0; i<b.vals.size(); i++) ans.vals.push_back(b.vals[i]);
    sort(all(ans));
    return ans;

}

void build(int id , int l , int r){
       if(l==r){
           t[id] = a[l];
           return ;
       }
       int mid = ((l+r)>>1);
       build(2*id , l , mid);
       build(2*id+1 , mid+1 , r );
       t[id] = merge(t[2*id] , t[2*id+1]);
       return ;
}

int query(int id , int l  , int r , int lq , int rq , int k){
            // i mean it's logical to return 0; int this situation ;
            if(rq < l || lq > r) return 0;

            if(l>=lq && r<=rq){
                return upper_bound(t[id].begin() , t[id].end() , k) - t[id].begin(); // and done bro what the fuck are you taking about mohter fucker;
            }
            int mid = (l+r)>>1;
            return query( id*2 ,  l  ,  mid ,  lq ,  rq ,  k) + query(2*id + 1 , mid+1 , r,lq , rq ,k);
}






int main(){

    return 0;
}

