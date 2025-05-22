#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> cubic(vector<int> &v){
    int N = v.size();
    vector<int> dp(N, 0);

    for(int i=0; i<N; i++){
        int mask = i;
        for(int j = mask; j > 0; j = (j-1)&mask){
            dp[mask] = (dp[mask] + v[j]);
        } 
        // here v[0] is not included in submask
        // dp[mask] = (dp[mask] + v[0]);
    }
    return dp;
}

// I am not sure if this function is correct or not as I did not understood it, just copied it from a video
vector<int> cubic2(vector<int> &v){
    int N = v.size();
    vector<int> dp(N, 0);

    for(int i=0; i<N; i++){
        int mask = i;
        int submask = 0;

        do{
            dp[mask] = (dp[mask] + v[submask]);
        } while(submask = ((submask-mask)&mask));
    }
    return dp;
}

signed main(){
    int n;
    cin>>n;

    int N = (1<<n);

    vector<int> v(N, 0);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }

    vector<vector<int>> dp(N, vector<int>(n+1, 0));

    for(int i=0; i<N; i++){
        dp[i][0] = v[i];
    }

    for(int mask=0; mask<N; mask++){
        for(int i=1; i<=n; i++){
            if(mask&(1<<(i-1))) dp[mask][i] = (dp[mask][i-1] + dp[mask^(1<<(i-1))][i-1]);
            else dp[mask][i] = dp[mask][i-1];
        }
    }

    // dp[i][j] ---> sum over subsets of i, if the last j bits (from right side) are allowed to toggle

    return 0;
}