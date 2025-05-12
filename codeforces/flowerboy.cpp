#include <iostream>
#include <vector>

using namespace std;


int solve(const vector<int>& a, const vector<int>& b) {
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        cout << solve(a, b) << '\n';
    }

    return 0;
}
