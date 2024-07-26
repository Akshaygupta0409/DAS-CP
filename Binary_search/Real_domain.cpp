#include<bits/stdc++.h>

using namespace std;



int main(){
    // alter syle but better
    // lets assume this  
    int double lo = 0; int double hi = n;
    for(int i=0; i<=40; i++){
         int mid = (hi - lo)/2;
         if(check(mid)){
            lo = mid ;

         }else{
             hi = mid;
         }
    }
   long double ans = (lo + hi)/ 2; 
    return 0;
}

