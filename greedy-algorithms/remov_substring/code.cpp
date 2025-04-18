#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
        std::ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--)
    {
        string s;
        int x;int y;
        cin>>s>>x>>y;
        int n; n=s.length();
        int ans1=0;int ans2=0;
            //remove all abs
             vector<char> st;
          for(int i=0;i<n;i++)
          {
              if(s[i]=='b')
              {
                if(!st.empty()&&st.back()=='a')
                {
                    ans1+=x;
                    st.pop_back();
                }
                    else
                    st.push_back('b');
              }
              else st.push_back(s[i]);  
          }
          stack<char> st1;
          for(int i=0;i<st.size();i++)
          {
            if(st[i]=='a')
            {
                if(!st1.empty()&&st1.top()=='b')
                {
                    st1.pop();
                    ans1+=y;
                }
                else st1.push('a');
            }
            else st1.push(st[i]);
          }
          while(!st1.empty()) st1.pop();
            while(!st.empty()) st.pop_back();
          for(int i=0;i<n;i++)
          {
              if(s[i]=='a')
              {
                if(!st.empty()&&st.back()=='b')
                {
                    ans2+=y;
                    st.pop_back();
                }
                    else
                    st.push_back('a');
              }
              else st.push_back(s[i]);  
          }
          for(int i=0;i<st.size();i++)
          {
            if(st[i]=='b')
            {
                if(!st1.empty()&&st1.top()=='a')
                {
                    st1.pop();
                    ans2+=x;
                }
                else st1.push('b');
            }
            else st1.push(st[i]);
          }
         cout<<max(ans1,ans2)<<endl;
    }
}