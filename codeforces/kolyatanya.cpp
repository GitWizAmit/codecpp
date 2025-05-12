#include<iostream>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binpow(int a, int b) {
    if (b == 0) return 1;
    int res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    int ans = (binpow(3, 3 * n) - binpow(7, n) + MOD) % MOD;
    cout << ans << endl;

    return 0;
}