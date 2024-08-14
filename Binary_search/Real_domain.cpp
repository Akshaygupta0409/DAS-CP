#include<bits/stdc++.h>

using namespace std;



int main(){
    // alter syle but better
    // lets assume this  
    // increase or decrease the value of 40 -> 60 -> 80 -> 100 for precision purpos;
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
   
   // method 2 may give errors sometime 
   int edps = 1e9
   while(abs(hi-lo) > eps){
      int mid = (lo + hi)/2;
      if(check(mid))
   }






    return 0;
}

