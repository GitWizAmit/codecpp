#include<iostream>
#include<cmath>
using namespace std;


void solve(int arr[], int n, int k, int q) {
    long long ans = 0;
    int left = 0, right = 0;

    while (right < n) {
        if (arr[right] > q) {
            int diff = right - left;
            long long count = diff - (k - 1);
            if (diff >= k) ans += ((count + 1) * count) / 2;
            right++;
            left = right;
        } else {
            right++;
        }
    }
    int diff = right - left;
    long long count = diff - (k - 1);
    if (diff >= k) ans += (count * (count + 1)) / 2;
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        solve(arr, n, k, q);
    }
    return 0;
}