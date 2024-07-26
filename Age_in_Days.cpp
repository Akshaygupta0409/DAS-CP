// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/template-code]

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while(T--){
         int N;
        cin>>N;
        int Y = N /365;
        int M = N % 365 / 30;
        int D = N - 365*Y - 30*M;
        cout<<Y<<" years"<<'\n'<<M<<" months"<<'\n'<<D<<" days"<<'\n';
    }
    return 0;
}