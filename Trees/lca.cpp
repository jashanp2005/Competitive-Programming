#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
using namespace std;
 
// implement lca and binary lifting
 
void dfs(int node, int par, vector<vector<int>> &adj, vector<vector<int>> &parent, vector<int> &depth, int d){
    parent[node][0] = par;
    depth[node] = d;
    for(int i=1; i<20; i++){
        if(parent[node][i-1] != -1) parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for(auto &it: adj[node]){
        if(it == par) continue;
        dfs(it, node, adj, parent, depth, d+1);
    }
}

// this accepts parameter k in one-based indexing --> k = 1, immediate parent
int kthParent(int node, int k, vector<vector<int>> &parent){
    for(int i = 19; i >= 0; i--){
        if(node == -1) return node;
        if(k & (1 << i)){
            node = parent[node][i];
        }
    }
    return node;
}
 
int findlca(int a, int b, vector<vector<int>> &parent, vector<int> &depth){
    int levela = depth[a];
    int levelb = depth[b];
    if(levela > levelb) swap(a, b);
 
    int diff = levelb - levela;
    a = kthParent(a, diff, parent);
 
    if(a == b) return a;
 
    for(int i=19; i>=0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}
 
signed main(){
    int n;
    cin>>n;
 
    int q;
    cin>>q;
 
    vector<vector<int>> adj(n);
    vector<vector<int>> parent(n, vector<int>(20, -1));
    vector<int> depth(n, 0);
 
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        a--;
 
        parent[i][0] = a;
 
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
 
    dfs(0, -1, adj, parent, depth, 0);
 
    while(q--){
        int node, level;
        cin>>node>>level;
        node--;
 
        int temp = kthParent(node, level, parent);
 
        if(temp == -1) cout<<temp<<endl;
        else cout<<temp+1<<endl;
    }
 
    return 0;
}