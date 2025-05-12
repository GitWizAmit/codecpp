#include<iostream>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binpow(int a, int b) {
    if(b == 0) return 1;
    int result = 1;
    while(b) {
        if (b % 2) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
} 

int fact[1000001];
int inv_fact[1000001];

int inverse(int a) {
    return binpow(a, MOD - 2);
}

void pre_compute_fact() {
    fact[0] = 1;
    for(int i = 1; i < 1000001; ++i) fact[i] = (i * fact[i - 1]) % MOD;

    // compute inverse
    inv_fact[1000000] = inverse(fact[1000000]);
    for(int i = 1000000; i >= 1; --i) inv_fact[i - 1] = (inv_fact[i] * i) % MOD;
}

int ncr_fact_faster(int n, int r) {
	int num = fact[n];
	int den = (inv_fact[n-r] * inv_fact[r]) % MOD;
	return (num * den) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    pre_compute_fact();
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ncr_fact_faster(a, b) << endl;
    }
    return 0;
}