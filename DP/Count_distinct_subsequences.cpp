#include<bits/stdc++.h>
using namespace std;

int count(string &s){
    int n = s.length();
    vector<int> last(26, -1);
    vector<int> dp(n+1, 1);
    for(int i=1; i<=n; i++){
        dp[i] = 2*dp[i-1];
        if(last[s[i-1]-'a'] != -1) dp[i] -= dp[last[s[i-1]-'a']];
        last[s[i-1]-'a'] = i-1;
    }
    return dp[n];
}

signed main(){
    string s;
    cin>>s;
    cout<<count(s)<<endl;
    return 0;
}