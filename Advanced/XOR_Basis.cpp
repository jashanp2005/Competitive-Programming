#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int d = 30;

vector<int> base(d+1, 0);

int sz = 0; // size of the basis

void insert(int num){
    
    for(int i=d; i>=0; i--){
        
        if((num&(1<<i)) == 0) continue;

        if(base[i] == 0){
            base[i] = num;
            sz++;
            return;
        }

        num = (num ^ base[i]);
    }

}

signed main(){
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> pre(n, 0);

    for(int i=0; i<n; i++){
        pre[i] = v[i];
        if(i) pre[i] = (pre[i] ^ pre[i-1]);

        insert(pre[i]);
    }

    if(pre[n-1] == 0) cout<<-1<<endl;

    else cout<<sz<<endl;

    return 0;
}