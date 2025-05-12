#include<iostream>
using namespace std;

#define ll long long

ll nCr(ll n, ll r) {
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

string solve(ll n, ll k) {
    string ans;
    ll count_a = n - 2;
    ll count_b = 2;

    while (count_b + count_a > 0) {
        if (count_a == 0) {
            ans += 'b';
            count_b--;
            continue;
        }
        if (count_b == 0) {
            ans += 'a';
            count_a--;
            continue;
        }
        
        ll curr_perm = nCr(count_a - 1 + count_b, count_b);
        if (curr_perm >= k) {
            ans += 'a';
            count_a--;
        } else {
            ans += 'b';
            k -= curr_perm;
            count_b--;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }

    return 0;
}