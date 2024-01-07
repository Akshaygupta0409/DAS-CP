#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

string s;

int tt;// current test-case
int testcase[100010][2][2]; // which testcase dp array is storing for


int dp[100010][2][2]; // dp cache array.

// t1 -> tight for same as Q from start or not. 
// t2 -> tight for larger or same as Q from end or not.
int rec(int pos,int t1,int t2){
    if(pos==s.length()){
        if(t2==0 && t1==0)
            return 1;// 1 valid string found.
        else
            return 0;
    }
    if(testcase[pos][t1][t2]==tt){ // check if the saved value is relevant for this testcase.
        return dp[pos][t1][t2];
    }
    int ans = 0;
    for(char dig = 'A'; dig<='Z'; dig++){
        if(t1==1&&dig<s[pos])continue;

        int nt1 = t1;
        if(t1==1&&dig>s[pos]) nt1 = 0;

        int nt2;
        if(dig==s[pos]){
            nt2 = t2;
        }else if(dig>s[pos]){
            nt2 = 0;
        }else{
            nt2 = 1;
        }

        ans =(ans + rec(pos+1,nt1,nt2))%mod;
    }
    testcase[pos][t1][t2] = tt;
    return dp[pos][t1][t2]=ans;
}

int main(){
    int t;cin>>t;
    for(tt=1;tt<=t;tt++){
        cin>>s;
        cout<<rec(0,1,1)<<endl;
    }
}


/*

The Larger String

Time-Limit: 5 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

String P is given, consisting of uppercase alphabets. You have to find the number of strings Q, such that string Q is lexicographically larger than string P and reverse of string Q is lexicographically larger than the reverse of string P. Since the answer can be large, print the number of integers modulo 109 + 7.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line and only line of input contain string P.


Output Format

For each test case, print the number of strings Q.


Constraints

1 ≤ T ≤ 100

1 ≤ |P| ≤ 105 where |P| is the length of string P.

It is guaranteed that the sum of |P| for all test cases is not greater than 105.


Sample Input 1

3
YZY
XY
ZZZZ

Sample Output 1

28
5
0

Note

For the first test case, Q will be valid when Q is YZZ or ZZY. Other 26 cases will be ZAZ to ZZZ.

For the second test case, the valid strings are XZ, YY, YZ, ZY, ZZ.

For the third test case, no string is greater than ZZZZ.

*/