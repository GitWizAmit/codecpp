#include<iostream>
using namespace std;

void solve(int n, int arr[], long long sum, unordered_map<int,int> um) {
    int q;
    cin >> q;
    while (q--) {
        int b, c;
        cin >> b >> c;
        if (um.find(b) == um.end()) {
            cout << sum << '\n';
        } else {
            int cnt = um[b];
            sum -= (b * 1LL * cnt);
            sum += (c * 1LL * cnt);
            um.erase(b);
            um[c] = cnt + um[c];
            cout << sum << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    long long sum = 0;
    unordered_map<int,int> um;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        um[arr[i]]++;
    }
    solve(n, arr, sum, um);
    return 0;
}