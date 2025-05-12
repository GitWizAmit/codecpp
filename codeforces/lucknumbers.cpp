#include<iostream>
using namespace std;

#define int long long

int binpow(int a, int b) {
    if (b == 0) return 1;
    int result = 1;
    while (b) {
        if (b % 2) result *= a;
        a = a * a;
        b >>= 1;
    }
    return result;
}

signed main() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += binpow(2, i);
    }
    cout << ans;
    return 0;
}