// Here The Code Starts
#include <bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
#define int long long
#define endl "\n"
#define f first
#define s second
int mod = 1000000007;
multiset<int>m;
int z;
vector<int>ans;
void rec(int i,int val ,int count){
    if(i==z){
        if(m.find(val)!=m.end() && count)m.erase(m.find(val));
        return;
    }
    rec(i+1,val,count);
    rec(i+1,val+ans[i],count+1);
}
//-------------------------------------------------------------------------
void question() {
int n;
cin>>n;
for(int i=0;i<(1<<n);i++){
    int x;
    cin>>x;
    m.insert(x);
}
m.erase(m.begin());

ans.push_back(*m.begin());
m.erase(m.begin());
while(1){
    if(m.size()==0)break;
    int val=*m.begin();
   // cout<<val<<endl;
    m.erase(m.begin());
    z=ans.size();
    rec(0,val,0);
    ans.push_back(val);
}
sort(ans.begin(),ans.end());
for(auto it:ans)cout<<it<<" ";
cout<<endl;
ans.clear();
m.clear();
return;
}
//-----------------------------------------------------------------------
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        question();
    }
    return 0;
}