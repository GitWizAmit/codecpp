#include<iostream>
using namespace std;

void solve(int n, string& s) {
    int ans = 0;
    int cnt = 0;
    for (auto ch : s) {
        if (ch == '1') cnt++;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') ans += (cnt - 1);
        else ans += cnt + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        solve(n, s);
    }
    return 0;
}