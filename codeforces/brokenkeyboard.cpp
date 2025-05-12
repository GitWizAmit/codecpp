#include<iostream>
using namespace std;


void solve(int arr[], string &s) {
    long long ans = 0;
    int left, right = 0;
    for (int i = 0; i < s.length(); ++i) {
        int j = i;
        while (arr[s[j] - 'a'] != 0 && j < s.length()) {
            j++;
        }
        long long count = j - i;
        ans += (count * (count + 1)) / 2;
        i = j;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int arr[26] = {};
    for (int i = 0; i < k ; ++i) {
        char ch;
        cin >> ch;
        arr[ch - 'a']++;
    }
    solve(arr, s);

    return 0;
}