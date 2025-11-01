#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 
vector<int> ans;
 
void dfs(int node, int parent, vector<set<int>*> &subtree, vector<vector<int>> &adj, vector<int> &col){
    int maxi = -1;
    for(auto &it: adj[node]){
        if(it == parent) continue;
        dfs(it, node, subtree, adj, col);
        if(maxi == -1 || subtree[maxi]->size() < subtree[it]->size()){
            maxi = it;
        }
    }
    if(maxi == -1){
        subtree[node] = new set<int>();
    }
    else{
        subtree[node] = subtree[maxi];
    }
    for(auto &it: adj[node]){
        if(it == parent || it == maxi) continue;
        subtree[node]->insert(subtree[it]->begin(), subtree[it]->end());
    }
    subtree[node]->insert(col[node]);
    ans[node] = subtree[node]->size();
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin>>n;
 
    vector<int> v(n);
    for(auto &it: v) cin>>it;
 
    vector<vector<int>> adj(n);
    vector<set<int>*> subtree(n);
 
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    ans.resize(n);
    dfs(0, -1, subtree, adj, v);
    
    for(auto &it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}