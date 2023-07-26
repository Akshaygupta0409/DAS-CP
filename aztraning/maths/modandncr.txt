#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using lli = long long int;

lli factorial(lli x){  // O(N)
    lli ans = 1;
    for(lli i=1;i<=x;i++){
        ans = (ans * i)%MOD;
    }
    return ans;
}

const int MAXN = 100100
int fact[MAXN];
int inv[MAXN];
void precompute(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    factinv[MAXN-1] = inv(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--){
        factinv[i] =  (factinv[i+1] * (i+1))% MOD; 
    }
}
lli ncr_fast(lli n,lli r){ //  O(1)
    lli ans = fact[n];
    ans = ans * factinv[n-r] % MOD;
    ans = ans * factinv[r] % MOD;
    return ans;
}

lli binpow(lli x,lli p){ // O(log(p))
    if(p==0)return 1;
    if(p%2==1){
        return x*binpow(x,p-1)%MOD;
    }else{
        lli temp = binpow(x,p/2);
        return temp*temp%MOD;
    }
}

lli inv(lli x){ // O(log(MOD))
    return binpow(x,MOD-2);
}

lli ncr(lli n,lli r){ // O(N + log(MOD))
    lli ans = factorial(n);
    ans = ans * inv(factorial(n-r)) % MOD;
    ans = ans * inv(factorial(r)) % MOD;
    return ans;
}


int fact[100100];
void precompute(){
    fact[0]=1;
    for(int i=1;i<100100;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}
lli ncr_fast(lli n,lli r){ //  O(log(MOD))
    lli ans = fact[n];
    ans = ans * inv(fact[n-r]) % MOD;
    ans = ans * inv(fact[r]) % MOD;
    return ans;
}

int main()
{ 
    precompute();
    // t,n,r <= 10^5
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        cout<<ncr(n,r)<<endl;
    }
    
}