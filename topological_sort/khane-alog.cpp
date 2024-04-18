#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000010000
#define endl '\n'
int n,m;

//******THIS ONE IS FOR DFS********************

// vector<vector<int>> g;

// vector<int>vis;
// vector<int> topo;

// void dfs(int node){
// 	vis[node]=1;
// 	for(auto v: g[node]){
// 		if(!vis[v]){
// 			dfs(v);
// 		}
// 	}
// 	topo.push_back(node);
// }

// //---- dp can be used bcoz there is no cycle----

// int dp[100100];
// int rec(int node){ // longest path startint at node.
// 	if(dp[node]!=-1){
// 		return dp[node];

// 	}
// 	int ans=0;
// 	for(auto v: g[node]){
// 		ans=max(ans, 1+rec(node));
// 	}
// 	return dp[node]=ans;
// }

// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	g.resize(n+1);
// 	vis.resize(n+1,0);
// 	for(int i = 0; i <m ; i++){
// 		int a,b;
// 		cin>>a>>b;
// 		g[a].push_back(b);
// 	}
// 	memset(dp,-1,sizeof(dp));
// 	for(int i = 1; i <=n ; i++){
// 		if(!vis[i]){
// 			dfs(i);
// 		}
// 	}
// 	reverse(topo.begin(),topo.end());

// 	for(auto v:topo){
// 		cout<<v<<" ";
// 	}
// }

// signed main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	// int _t; cin>>_t;while(_t--)
// 	solve();
// }

//*********************************

//**********THIS IS FOR BFS**************

// this is imp
// use bfs only for topo
// for cycle it will not be able to eleminate the cycle 


// vector<vector<int>> g;
// vector<int> indeg;//outdeg;
// vector<int> topo;

// void kahn(){
// 	queue<int>q;
// 	for(int i = 1; i <=n ; i++){
// 		if(indeg[i]==0) q.push(i);
// 	}
// 	while(!q.empty()){
// 		int cur=q.front();
// 		q.pop();
// 		topo.push_back(cur);
// 		for(auto v:g[cur]){
// 			indeg[v]--;
// 			if(indeg[v]==0){
// 				q.push(v);
// 			}
// 		}
// 	}
// }

// void solve(){
	
// 	cin>>n>>m;
// 	g.resize(n+1);
// 	indeg.assign(n+1,0);
// 	// outdeg.assign(n+1,0);
// 	for(int i = 0; i <m ; i++){
// 		int a,b;
// 		cin>>a>>b;
// 		g[a].push_back(b);
// 		// indeg maintain
// 		indeg[b]++;
// 		// outdeg[a]++;
// 	}
// 	kahn();
// 	if(topo.size()!=n){ 
// 		cout<<"there is a cycle\n";

// 	}else{
// 		for(auto v:topo){
// 			cout<<v<<" ";
// 		}
// 	}
// }

// signed main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	// int _t; cin>>_t;while(_t--)
// 	solve();
// }

//**********************************************
// if i have to maintain a lexicographical order

vector<vector<int>> g;
vector<int> indeg;//outdeg;
vector<int> topo;

void kahn(){
	priority_queue<int>q;
	for(int i = 1; i <=n ; i++){
		if(indeg[i]==0) q.push(-i);
	}
	while(!q.empty()){
		int cur= -q.top();
		q.pop();
		topo.push_back(cur);
		for(auto v:g[cur]){
			indeg[v]--;
			if(indeg[v]==0){
				q.push(-v);
			}
		}
	}
}

void solve(){
	
	cin>>n>>m;
	g.resize(n+1);
	indeg.assign(n+1,0);
	// outdeg.assign(n+1,0);
	for(int i = 0; i <m ; i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		// indeg maintain
		indeg[b]++;
		// outdeg[a]++;
	}
	kahn();
	if(topo.size()!=n){ 
		cout<<-1;

	}else{
		for(auto v:topo){
			cout<<v<<" ";
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int _t; cin>>_t;while(_t--)
	solve();
}