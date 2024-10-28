#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int mod = 1e9 + 7; 
const int base = 31;      // Base for hashing

// Function to calculate hash of a string
int calculateHash(const string &s) {
    int hash = 0;
    int p_pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * base) % mod;
    }
    return hash;
}

// Function to find occurrences of a pattern in a text using Rabin-Karp algorithm
vector<int> rabinKarp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return {};  // No matches if pattern is longer than text

    int patternHash = calculateHash(pattern);
    int currentHash = calculateHash(text.substr(0, m));

    // Powers of base to maintain the rolling hash
    int p_pow = 1;
    for (int i = 0; i < m - 1; ++i) {
        p_pow = (p_pow * base) % mod;
    }

    vector<int> occurrences;
    for (int i = 0; i <= n - m; ++i) {
        if (currentHash == patternHash) {
            if (text.substr(i, m) == pattern)  // Double-check for collision
                occurrences.push_back(i);  // Match found at index i
        }
        
        // Rolling hash update for next substring
        if (i < n - m) {
            currentHash = (currentHash - (text[i] - 'a' + 1) * p_pow % mod + mod) % mod;
            currentHash = (currentHash * base + (text[i + m] - 'a' + 1)) % mod;
        }
    }
    
    return occurrences;
}

signed main() {
    return 0;
}
