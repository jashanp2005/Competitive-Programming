#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> parent;
vector<int> depth;
vector<vector<int>> adj;

void dfs(int node, int par, int d){
    parent[node][0] = par;
    for(int i=1; i<=20; i++){
        if(parent[node][i-1] != -1){
            parent[node][i] = parent[parent[node][i-1]][i-1];
        }
        else{
            parent[node][i] = -1;
        }
    }
    for(auto &it: adj[node]){
        if(it == par) continue;
        depth[it] = d + 1;
        dfs(it, node, d+1);
    }
}
 
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    for(int i=20; i>=0; i--){
        if(d&(1<<i)){
            a = parent[a][i];
        }
    }
    if(a == b) return a;
    for(int i=20; i>=0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int kthParent(int node,int k){
    if(k == 0) return node;
    if(node == -1) return -1;
    while(k > 0){
        int log_val = log2(k);
        node = parent[node][log_val];
        if(node == -1) return -1;
        k -= (1<<log_val);
    }
    return node;
}
 
int main() {
    int n, q;
    cin>>n>>q;

    parent.resize(n, vector<int>(21, 0));
    depth.resize(n, 0);
    adj.resize(n, vector<int>());

    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        a--;
        parent[i][0] = a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    dfs(0, -1, 0);


    // to tell distance between two nodes
    int x, y;
    cin>>x>>y;
    int temp = lca(x, y);
    cout<<depth[x] + depth[y] - 2*(depth[temp])<<endl;
 
    return 0;
}