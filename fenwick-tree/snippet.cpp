#include<bits/stdc++.h>

using namespace std;


// sum;

class BIT{
    vector<int> bitarray;
    int n ;
    // initializtion
    public : 
    BIT(int n_){
          bitarray.assign(n_+1 , 0);
          this->n = n_;
    }
    int LSB(int i) {return (i & (-i));}

     void update(int idx , int inc){
           for(int i=idx ; i<=n; i+= LSB(i)){
               bitarray[idx] += inc;
           }
     }
    void build(vector<int> &array){
           for(int i=1; i<=n; i++) {
              update(i , array[i]);
           }
    }
     // return the sum for 1 --- r cant do anything this is how the algo works; :-)
    int query(int r){
         int sum = 0;

         for(int i=r; i>0; i -= LSB(i)){
              sum += bitarray[i];
         }

         return sum;
    }
};





int main(){

    return 0;
}

