#include<bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;
    public:
    SGTree(int n){
        seg.resize(4*n, INT_MIN);
    }
    void build(int index, int low, int high, vector<int> &v){
        if(low == high){
            seg[index] = v[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*index+1, low, mid, v);
        build(2*index+2, mid+1, high, v);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
    }
    int query(int index, int low, int high, int l, int r){
        if(low >= l && high <= r) return seg[index];
        if(high < l || low > r) return INT_MIN;
        int mid = (low + high)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return max(left, right);
    }
    void update(int index, int low, int high, int i, int val){
        if(low == high){
            seg[index] = val;
            return;
        }
        int mid = (low + high)/2;
        if(i <= mid) update(2*index+1, low, mid, i, val);
        else update(2*index+2, mid+1, high, i, val);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
    }
};

int main(){
    return 0;
}