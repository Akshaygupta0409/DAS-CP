#include<bits/stdc++.h>

using namespace std;

// what if you are give and input like this 
// akshay gupta
// abhishek
// then just follow this codeing syle ;

int main(){
    // given n -> number of names in hand ;
    int n; 
    cin >> n;
    string temp="";
    getline(cin , temp); // why used this getline and temprary temp string ;
    // because of cin >> n; what will happed is the first getline in the for loop will have \n as firt arugment ;
    string arr[n];
    for(int i=0; i<n; i++){
          getline(cin , arr[i]);
    }
    return 0;
}

