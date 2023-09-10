#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define mod 1000000007
const double pi=acos(-1);
using namespace std;

vector<int> mp(1000001,0);

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    int dist=0;

    for(int i=0;i<n;i++)
    cin>>a[i];

    int tail=0,head=-1,ans=INT_MAX;
    while(tail<n)
    {
        while(head+1<n && (head+1-tail+1<=k))
        {
            head++;
            mp[a[head]]++;
            if(mp[a[head]]==1)
            dist++;

            if(head-tail+1==k)
            ans=min(ans,dist);
        }

        if(head-tail+1==k)
        ans=min(ans,dist);

        if(tail>head)
        {
            tail++;
            head=tail-1;
        }
        else 
        {
            mp[a[tail]]--;
            if(mp[a[tail]]==0)
            dist--;
            tail++;
        }

    }

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    //string temp;getline(cin,temp);
    while(t--)
    {
        solve();
    }
}