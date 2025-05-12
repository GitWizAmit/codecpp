#include<iostream>
#include<vector>
using namespace std;

int countComplementaryWays(const vector<int>& a, const vector<int>& b, int k) {
    int n = a.size();
    int known_x = -1;
    bool has_known = false;

    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            int candidate = a[i] + b[i];
            if (has_known && candidate != known_x)
                return 0;
            known_x = candidate;
            has_known = true;
        }
    }

    if (has_known) {
        for (int i = 0; i < n; ++i) {
            if (b[i] == -1) {
                int val = known_x - a[i];
                if (val < 0 || val > k)
                    return 0;
            }
        }
        return 1;
    } else {
        int low = 0, high = 2 * k;
        for (int i = 0; i < n; ++i) {
            low = max(low, a[i]);
            high = min(high, a[i] + k);
        }
        if (low > high) return 0;
        return high - low + 1;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        
       cout << countComplementaryWays(a, b, k) << '\n';
    }

    return 0;
}