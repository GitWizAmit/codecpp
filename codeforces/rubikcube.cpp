#include<iostream>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binpow(int a, int b) {
    if (b == 0) return 1;
    int res = 1;
    a %= MOD;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int mod_inv(int a) {
    return binpow(a, MOD - 2);
}

void solve(int k) {
    if (k == 1) {
        cout << 6;
        return;
    }

    int total_nodes = (1LL << k) - 1;
    int last_level_nodes = total_nodes - (total_nodes / 2);
    int node_with_neighbour = total_nodes - last_level_nodes;

    int exp1 = last_level_nodes % (MOD - 1);
    int exp2 = (node_with_neighbour - 1 + MOD - 1) % (MOD - 1);

    int permute_last_nodes = binpow(4, exp1);
    int permute_remaining_nodes = binpow(4, exp2);

    int ans = (((permute_last_nodes * permute_remaining_nodes) % MOD) * 6) % MOD;

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int k;
    cin >> k;
    solve(k);
    return 0;
}