#include<iostream>
using namespace std;

const int MOD = 998244353;

void solve(string &s, int n) {
    long long ans = 0;
    int start = -1, end = -1;
    for (int i = 1; i < n; ++i) {
        if (start == -1 && s[i] != s[i - 1]) start = i - 1;
        else if (start != -1 && s[i] != s[i - 1]) end = i - 1;
    }

    end = (end == -1 ? start : end);

    long long len1 = start + 1;
    long long len2 = n - end - 1;
    long long len3 = start + 1;

    if (start == end || s[start] != s[end + 1]) ans = len1 + len2 + 1;
    else ans = (((len1 * len2) % MOD) + len2 + len3 + 1) % MOD;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    solve(s, n);
    return 0;
}
