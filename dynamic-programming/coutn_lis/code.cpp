# include<bits/stdc++.h>
using namespace std;
# define int long long int
int m=1e9+7;

int mod(int x)
{
    return (x%m + m)%m;
}
int add(int x,int y)
{
    return mod(mod(x)+mod(y));
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr;
    arr.resize(n+1);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    vector<int>dp(n,1);
    vector<int>cnt(n,1);
    
    int maxd=0;
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]>arr[prev]&&1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
                cnt[i]=cnt[prev];
            }
            else if(arr[i]>arr[prev]&&1+dp[prev]==dp[i])cnt[i]=add(cnt[i],cnt[prev]);
            
        }
        maxd=max(maxd,dp[i]);
    }
    
    int ans=0;
    for(int k=0;k<n;k++)
    {
        if(dp[k]==maxd)ans=add(ans,cnt[k]);
    }
    cout<<ans<<'\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}