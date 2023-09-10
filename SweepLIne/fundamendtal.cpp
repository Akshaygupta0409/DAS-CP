#include<bits/stdc++.h>
using namespace std;



#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

class MyStructure {
private:
    multiset<int> M1, M2;
    ll sum;
    int K;

public:
    MyStructure(int K) : K(K), sum(0LL) {};

    void add(int x) {
        M1.insert(x);
        sum += x;
        if((int)M1.size() > K) {
            int y = *(M1.begin());
            M1.erase(M1.find(y));
            sum -= y;
            M2.insert(y);
        }
        return;
    }

    void erase(int x) {
        if(M2.find(x) != M2.end()) {
            M2.erase(M2.find(x));
        }
        else if(M1.find(x) != M1.end()) {
            sum -= x;
            M1.erase(M1.find(x));
            if(M2.empty()) return;
            int y = *(M2.rbegin());
            sum += y;
            M1.insert(y);
            M2.erase(M2.find(y));
        }
        return;
    }

    ll getSum() {
        return sum;
    }
};


#define F first
#define S second

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<pair<int,pair<int,int>>> events;
    
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({l,{0,x}});
        events.push_back({r,{2,x}});
    }
    
    int q;
    cin>>q;
    int final_ans[q];
    for(int i=0;i<q;i++){
        int y;
        cin>>y;
        events.push_back({y,{1,i}});
    }
    
    sort(events.begin(),events.end());
    
    MyStructure topk(k);
    for(int i=0;i<events.size();i++){
        if(events[i].S.F==0){
            // segment with value events[i].S.S is starting
            topk.add(events[i].S.S);
        }
        else if(events[i].S.F==2){
            // segment with value events[i].S.S is ending
            topk.erase(events[i].S.S);
        }else{
            int ans = topk.getSum();
            // answer query number events[i].S.S 
            final_ans[events[i].S.S] = ans;
        }
    }
    
    for(int i=0;i<q;i++){
        cout<<final_ans[i]<<endl;
    }
}