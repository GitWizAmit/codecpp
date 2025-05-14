#include<iostream>
#include <unordered_map>

using namespace std;

#define int long long
#define endl '\n'

unordered_map<int,int> len;

int getLength(int n) {
    if (n == 0 || n == 1) return 1;
    if (len.count(n)) return len[n];

    return len[n] = 2 * getLength(n / 2) + 1;
}

int solve(int n, int l, int r) {
    if (n == 0 || l > r) return 0;
    if (n == 1) return 1;

    int len = getLength(n);
    int half = getLength(n / 2);

    if (l > len || r < 1) return 0;
    if (r <= half) return solve(n / 2, l, r);
    if (l > half + 1) return solve(n / 2, l - half - 1, r - half - 1);

    int left = solve(n / 2, l, half);
    int middle = (l <= half + 1 && r >= half + 1) ? (n % 2 == 1) : 0;
    int right = solve(n / 2, 1, r - half - 1);

    return left + middle + right;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r);

    return 0;
}