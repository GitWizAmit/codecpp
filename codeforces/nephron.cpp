#include<iostream>

using namespace std;

#define int long long
#define endl '\n'

const int MAX = 1e5+1;
int total_length[MAX];

string base = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";

void precompute() {
    total_length[0] = 75;
    for (int i = 1; i < MAX; ++i) total_length[i] = min((long long) 1e18, 2 * total_length[i - 1] + 68);
}

char getKthChar(int n, int k) {
    if (n == 0) return base[k - 1];
    if (k <= a.length()) return a[k - 1];

    if (k <= a.length() + total_length[n - 1]) return getKthChar(n - 1, k - a.length());
    if (k <= a.length() + total_length[n - 1] + b.length()) return b[k - a.length() - total_length[n - 1] - 1];
    if (k <= a.length() + 2 * total_length[n - 1] + b.length()) return getKthChar(n - 1, k - a.length() - total_length[n - 1] - b.length());
    
    return c[k - a.length() - 2 * total_length[n - 1] - b.length() - 1];
}

void solve(int q) {
    string ans;
    while (q--) {
        int n, k;
        cin >> n >> k;
        if (total_length[n] < k) ans += '.';
        else ans += getKthChar(n, k);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    precompute();
    int q;
    cin >> q;
    solve(q);
    return 0;
}