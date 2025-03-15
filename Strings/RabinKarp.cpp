#include <bits/stdc++.h>
using namespace std;

#define int long long
class RollingHash{
    const int MOD1 = 1e9 + 7;
    const int MOD2 = 998244353;
    const int BASE1 = 5689;
    const int BASE2 = 1987;

    vector<pair<int, int>> hashValues;
    vector<pair<int, int>> powerBase;

public:
    RollingHash(string text){
        int n = text.size();
        // 1-based indexing
        hashValues.assign(n + 1, {0, 0});
        powerBase.assign(n + 1, {1, 1});

        for(int i = 1; i <= n; i++){
            char ch = text[i - 1];
            int charValue = ch - 'a' + 1;

            hashValues[i] = {
                (hashValues[i - 1].first * BASE1 + charValue) % MOD1,
                (hashValues[i - 1].second * BASE2 + charValue) % MOD2
            };

            powerBase[i] = {
                (powerBase[i - 1].first * BASE1) % MOD1,
                (powerBase[i - 1].second * BASE2) % MOD2
            };
        }
    }

    // l, r --> 0 based indexing
    pair<int, int> getHash(int l, int r){
        l++; r++;  // 1-based indexing
        int length = r - l + 1;
        int hash1 = (hashValues[r].first - (hashValues[l - 1].first * powerBase[length].first) % MOD1 + MOD1) % MOD1;
        int hash2 = (hashValues[r].second - (hashValues[l - 1].second * powerBase[length].second) % MOD2 + MOD2) % MOD2; 
        return {hash1, hash2};
    }
};
#undef int

signed main() {
    return 0;
}
