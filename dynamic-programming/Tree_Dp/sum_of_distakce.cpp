#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> g[100010];
int val[100010], subsum[100010], indp[100010], outdp[100010];
int tot;

void indfs(int nn, int pp){
    subsum[nn]=val[nn];
    for(auto v:g[nn]){
        if(v!=pp){
            indfs(v, nn);
            subsum[nn]+=subsum[v];
            indp[nn]+=indp[v]+subsum[v];
        }
    }
}

void outdfs(int nn, int pp, int outval){
    outdp[nn]=outval;
    for(auto v:g[nn]){
        if(v!=pp){
            outdfs(v, nn, outdp[nn]+indp[nn]-indp[v]-subsum[v]+tot-subsum[v]);
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        indp[i]=0;
        outdp[i]=0;
        val[i]=0;
        subsum[i]=0;
    }
    tot=0;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        tot+=val[i];
    }
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1, 0);
    outdfs(1, 0, 0);
    int minval=1e18, maxval=-1e18;
    for(int i=1;i<=n;i++){
        minval=min(minval, indp[i]+outdp[i]);
        maxval=max(maxval, indp[i]+outdp[i]);
    }
    cout<<maxval<<" "<<minval<<endl;
}

#undef int

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}