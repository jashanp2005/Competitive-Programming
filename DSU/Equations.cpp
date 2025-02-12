// There is a sequence A = a0, a1, ..., an-1. You are given the following information and questions.

// 1) relate(x, y, z): ay is greater than ax by z.
// 2) diff(x, y): report the difference between ax and ay i.e. ay - ax.

// The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 2 x 105).
// Then, q queries are given in the form either 0 x y z or 1 x y (0 ≤ x, y < n, x != y, 0 ≤ z ≤ 10000). 
// '0' denotes the relate information and '1' denotes diff question.
// It is guaranteed that there is no inconsistency in the given information.

// For each diff question, print the difference between ax and ay i.e. ay - ax. 
// If we don't have any information for the current diff query, print '?'.

#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int mod = 1e9+7;

class Disjoint{
    // all 0 based

    public:
    vector<int> parent, size, value;
    vector<vector<int>> adj;

    Disjoint(int n){
        parent.resize(n);
        size.resize(n);
        value.resize(n);
        adj.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
            value[i] = 0;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    int findDiff(int u, int v){
        if(findUPar(u) != findUPar(v)) return inf;
        return value[u] - value[v];
    }

    void dfs(int node, int par, int diff){
        value[node] += diff;
        for(auto &it: adj[node]){
            if(it == par) continue;
            dfs(it, node, diff);
        }
    }
    
    void unionBySize(int u, int v, int val){
        int x = findUPar(u);
        int y = findUPar(v);

        if(x == y) return;
        
        if(size[x] < size[y]){
            int diff = value[v] - value[u] + val;
            dfs(x, -1, diff);
            parent[x] = y;
            size[y] += size[x];
        }
        else{
            int diff = value[u] - value[v] - val;
            dfs(y, -1, diff);
            size[x] += size[y];
            parent[y] = x;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
};


signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;

    Disjoint ds(n);

    while(q--){
        int type;
        cin>>type;

        // 0 based input
        
        if(type == 0){
            // combine operation
            int a, b, c;
            cin>>a>>b>>c;
            ds.unionBySize(a, b, c);
        }
        else{
            int a, b;
            cin>>a>>b;
            int val = ds.findDiff(a, b);
            if(val == inf) cout<<"?"<<endl;
            else cout<<val<<endl;
        }
    }

    return 0;
}