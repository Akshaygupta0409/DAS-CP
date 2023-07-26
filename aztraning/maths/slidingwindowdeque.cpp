
struct monotone_deque{
    deque<int> dq;
    void insert(int x){ // O(k) worst case, O(1) amourtized
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void erase(int x){ // O(1)
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    int getmin(){ // O(1)
        return dq.front();
    }
};
// k= 3
// [1 2 3 4 5 6 ]
          ^ ^        

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    monotone_deque dq;
    for(int i=0;i<k-1;i++){
        dq.insert(arr[i]);
    }
    for(int i=k-1;i<n;i++){ //O(n+k)
        dq.insert(arr[i]);
        if(i>=k-1)dq.erase(arr[i-k]);
        cout<<dq.getmin()<<" ";
    }
}