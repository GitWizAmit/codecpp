#include<iostream>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int solve(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    int prev = 1, pprev = 0;
    for (int i = 3; i <= n; ++i) {
        int temp = prev;
        prev = ((i - 1) * ((prev % MOD + pprev % MOD) % MOD) % MOD);
        pprev = temp;
    }
    return prev;
}

signed main() {
    int n;
    cin >> n;

    cout << solve(n);
    return 0;
}