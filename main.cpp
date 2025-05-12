#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& v, int n, int k) {
    bool isSorted = true;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] <= v[i + 1]) {
            continue;
        }
        isSorted = false;
        break;
    }
    if (isSorted) {
        cout<<"YES"<<"\n";
        return;
    }

    // if k is 1 then it's not possible to arrange
    cout<<(k == 1 ? "NO" : "YES")<<"\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }
        solve(v, n, k);
    }
    return 0;
}