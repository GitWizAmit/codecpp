#include<iostream>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binpow(int a, int b) {
    if (b == 0) return 1;
    int result = 1;
    while (b) {
        if (b % 2) result = ((result % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return result;
}

signed main() {
    int n;
    cin >> n;

    cout << binpow(2, n);
    return 0;
}