// concept of map using multiset structure


struct map_using_multiset{
    multiset<pair<int,int>> mt;
    
    int set(int x,int k){ // mp[x] = k
        auto it = mt.lower_bound(make_pair(x,-1e9)); // log(n)
        auto end_it = mt.end();
        if(it==end_it){
            mt.insert(make_pair(x,k)); // log(n)
        }else if(it->first!=x){
            mt.insert(make_pair(x,k)); // log(n)
        }else{
            it->second = k;
        }
    }
    int get(int x){ // mp[x]
        auto it = mt.lower_bound(make_pair(x,-1e9)); // log(n)
        if(it==end_it){
            mt.insert(make_pair(x,0)); // log(n)
            return 0;
        }else if(it->first!=x){
            mt.insert(make_pair(x,0)); // log(n)
            return 0;
        }else{
            return it->second;
        }
    }
    
}

// sliding window classic problem 
// O(nlogk)
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // build the first window
    multiset<int> mt;
    for(int i=0;i<k;i++){
        mt.insert(arr[i]); // O(log(k))
    }
    // print answer for the first window
    cout<<(*mt.begin())<<" "; // O(1)
    
    for(int i=0;i<n-k;i++){
        // shift window one by one and print answer.
        mt.erase(mt.find(arr[i])); // O(log(k))
        mt.insert(arr[i+k]);  // O(log(k))
        cout<<(*mt.begin())<<" "; // O(1)
    }
    cout<<endl;
    
}

// another implementation if constraints are of the order 10e7 the monotonic deque is
// used to calculate it in o(N+k) ;