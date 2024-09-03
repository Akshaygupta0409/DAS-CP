#include<bits/stdc++.h>

using namespace std;



vector<vector<pair<int , int>>> t;
vector<int> m;

int ans = 0;
void dfs(int node , int par , int sum){
       
       for(auto child : t[node]){
            if(child.first == par) continue;
            dfs(child.first , node , sum + child.second);
       }

       if(sum > m[node-1]) ans++;

       return ;
}


int getMinServers(int server_nodes , vector<int> server_from , vector<int> server_to , vector<int> server_weight , vector<int> minActivity){
       t.clear();
       t.resize(server_nodes + 1);
       for(int i=0; i<=server_nodes-1; i++){
           t[server_from[i]].push_back(make_pair(server_to[i] , server_weight[i]));
           t[server_to[i]].push_back(make_pair(server_from[i] , server_weight[i]));
        }
        m = minActivity;
        dfs(1 , 0 , 0);

        return ans;
}






int main(){

    return 0;
}







