#include<bits/stdc++.h>
using namespace std;

int n;

// n queens porblem 

// lccm framework
// datastructure to store current_solution
vector<int> queens;

void printer(int level){
    cout<<"level : "<<level<<", queens : [";
    for(auto v:queens){
        cout<<v<<", ";
    }
    cout<<"]"<<endl;
}

bool check(int row,int col){
    for(int pr=0;pr<row;pr++){
        int pc = queens[pr];
        
        if(pc==col|| abs(pc-col)==abs(pr-row)){
            return false;
        }
    }
    return true;
}

int cnt = 0;

void rec(int level){ // recursion with level
    
    // base case
    if(level==n){
        // we have a solution in current_solution !
        cnt++;
        printer(level);
        // make sure to return !
        return;
    }
    
    // enumerate choices
    for(int col=0;col<n;col++){
        // check if this choice is feasible based on previous taken elements
        if(check(level,col)){ 
            // make move.
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }ai
    }
}

int main(){
    cin>>n;
    rec(0);
    cout<<cnt<<endl;
}