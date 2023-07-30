#include<bits/stdc++.h>
using namespace std;

void option_one(int n){
    // generater using permutation, check equation
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int cnt = 0;
    do{
        int abcde = 10000*arr[0] + 1000*arr[1] + 100*arr[2] + 10*arr[3] + 1*arr[4];
        int fghij = 10000*arr[0+5] + 1000*arr[1+5] + 100*arr[2+5] + 10*arr[3+5] + 1*arr[4+5];
        if(abcde%fghij==0){
            if(abcde/fghij == n){
                cout<< abcde<<" "<<fghij<<endl;
                cnt++;
            }
        }
    }while(next_permutation(arr,arr+10));
    cout<<cnt<<endl;
}

void option_two(int n){
    int cnt = 0;
    // generater using equation, check permutation
    for(int fghij = 01234; fghij <= 98765/n; fghij++){
        int abcde = fghij * n;
        
        // check if all distinct digits
        set<int> st;
        
        int temp = abcde;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp/=10;
        }
        
        temp = fghij;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp/=10;
        }
        
        if(st.size()==10){
            cnt++;
            cout<<abcde<<" "<<fghij<<endl;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    int n;
    cin>>n;
    option_two(n);
}