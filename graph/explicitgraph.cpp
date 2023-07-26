#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

void printer(vector<int> v){
    cout<<"[ ";
    for(auto x:v){
        cout<<x<<"\t";
    }
    cout<<"] ";
}
void printer(vector<vector<int>> v){
    cout<<"[ ";
    for(auto x:v){printer(x);cout<<endl;}
    cout<<"] ";
}

const int INF = 100;


/*
4 6
..#...
S.#.#.
....#.
..#..E
*/

int n,m;
vector<string> arr;

using state = pair<int,int>;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#'){
        return 1;
    }
    return 0;
}

vector<state> neighbours(state node){
    vector<state> ans;
    for(int i=0;i<4;i++){
        int nx = node.F + dx[i];
        int ny = node.S + dy[i];
        if(is_valid(nx,ny)){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}


vector<vector<int>> dis;
vector<vector<state>> par;

void bfs(state sc){
    dis.assign(n,vector<int>(m,INF));    
    par.assign(n,vector<state>(m,{-1,-1})); 
    
    queue<state> q;
    
    dis[sc.F][sc.S] = 0;
    q.push(sc);
    
    while(!q.empty()){
        state node = q.front();q.pop();
        for(auto v:neighbours(node)){
            if(dis[v.F][v.S]==INF){
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                par[v.F][v.S] = node;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i]="";
        for(int j=0;j<m;j++){
            char ch;cin>>ch;
            arr[i]+=ch;
        }
    }
    
    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }
    
    bfs(st);
    if(dis[en.F][en.S]==INF){
        cout<<"Not possible to reach\n";
    }else{
        cout<<dis[en.F][en.S]<<endl;
    }
    
    vector<state> path;
    state cur = en;
    while(cur!=make_pair(-1,-1)){
        path.push_back(cur);
        cur = par[cur.F][cur.S];
    }
    
    reverse(path.begin(),path.end());
    
    for(auto v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }
    
    printer(dis);
}

int main(){
    solve();
}