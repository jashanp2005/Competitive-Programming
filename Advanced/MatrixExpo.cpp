#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void multiplyMatrices(vector<vector<int>> &A, vector<vector<int>> &B) {
    int a = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod;
    int b = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod;
    int c = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod;
    int d = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void matrixExponentiation(vector<vector<int>> &A, int n) {
    vector<vector<int>> result = {{1, 0}, {0, 1}}; // identity matrix
    vector<vector<int>> base = A;

    while (n > 0) {
        if (n & 1) {
            multiplyMatrices(result, base);
        }
        multiplyMatrices(base, base);
        n >>= 1;
    }

    A = result;
}

int getNthFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<vector<int>> ans = {{1, 1}, {1, 0}};
    matrixExponentiation(ans, n - 1);
    
    return ans[0][0];  // F(n) is stored in ans[0][0] after exponentiation
}

int32_t main() {
    int n;
    cin >> n;  // Input the Fibonacci term you want to calculate

    cout << getNthFibonacci(n) << endl;

    return 0;
}
