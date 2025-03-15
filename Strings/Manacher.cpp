#include<bits/stdc++.h>
using namespace std;

class Manacher {
    string T;
    vector<int> P;
    int n;

public:
    Manacher(string& s) {
        T = "^";
        for (char c : s) T += "#" + string(1, c);
        T += "#$";

        n = T.size();
        P.assign(n, 0);
        int center = 0, right = 0, maxLen = 0, maxCenter = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (i < right)
                P[i] = min(right - i, P[mirror]);

            while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
                P[i]++;

            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }
    }

    pair<int, string> longestPalindrome(string& s) {
        int maxLen = 0, maxCenter = 0;

        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                maxCenter = i;
            }
        }

        int start = (maxCenter - maxLen) / 2;
        return {maxLen, s.substr(start, maxLen)};
    }

    bool isPalindromeQuery(int i, int j) {
        int ti = 2 * i + 2; 
        int tj = 2 * j + 2;
        int center = (ti + tj) / 2;
        int required = tj - center;

        return P[center] >= required;
    }
};

signed main(){
    return 0;
}