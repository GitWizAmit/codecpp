#include<iostream>
#include<unordered_map>
using namespace std;

#define int long long

void solve(int arr[], int n) {
    sort(arr, arr + n);
    int min = arr[n - 1] - arr[0];

    unordered_map<int, int> u_map;
    for (int i = 0; i < n; ++i) u_map[arr[i]]++;

    int ans = 0;
    for (auto &p : u_map) {
        int key = min + p.first;
        if (u_map.find(key) != u_map.end()) {
            if (key == p.first) ans += (p.second * (p.second - 1) / 2);
            else ans += (p.second * u_map[key]);
        }
    }
    cout << min << " " << ans;
}

signed main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    solve(arr, n);
    return 0;
}