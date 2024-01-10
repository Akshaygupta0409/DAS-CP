/*

Closest Points

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Given coordinates of the N points, find the K closest point to the origin. Print the points in order - 

The closest point to the origin first.
If the distance is the same, then one with the smallest ‘X coordinate.

Input Format

The first line contains two space-separated integers N, K (1 ≤ K ≤ N ≤ 10^6).

The next N lines contain Coordinates of the points (1 ≤ X, Y ≤ 10^5).

Try to do it in NlogK. In the actual interview after NlogN solution, you will have to optimize it further to NlogK solution.


Output Format

Print K closest points in the order mentioned in the statement.


Sample Input 1

5 3
1 5
7 8
8 1
1 6
2 4

Sample Output 1

2 4
1 5
1 6



*/


#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define nl '\n'
#define F first
#define S second
#define MP make_pair
#define fa false
#define tr true
using namespace std;
using ii= pair<long long,long long>;
// using lli = long long int ;
using vi= vector<long long>;
using vv= vector<vector<long long>>;
using vpi =vector<pair<long long,long long>>;

void init_code()
{
   fast_io;
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif 
}

// main logic 
struct Point{
    int  dist , x,y;
    bool operator<(const Point &a) const{
     return dist < a.dist;
    }
};
// this logic does it in nlogk iteration reather than nlogn ierationns;
void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<Point> pq;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        p.dist = p.x * p.x + p.y * p.y;
        pq.push(p);
        if(pq.size()<k){
            pq.push(p);
        }else{
            auto pqpoint = pq.top();
            if(pqpoint>p){
                pq.pop();
                pq.push(p);
            }
        }
    }
    vector<pair<int, int>> closestPoints;
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        closestPoints.push_back({p.x, p.y});
    }
    reverse(closestPoints.begin(), closestPoints.end());
    for (auto p : closestPoints) {
        cout << p.first << " " << p.second << endl;
    }
    return;
}


#undef int

int main()
{   
     init_code(); 
     int t=1;
     //cin>>t;
     while(t--)
     {
      solve();
      
      }
       
}