#include<iostream>
#include<vector>
using namespace std;


void buildPermutationMaxColorX(int n, int x) {
    vector<int> p;
    for (int i = 0; i < x; ++i) {
        p.push_back(i);
    }
    for (int i = x + 1; i < n; ++i) {
        p.push_back(i);
    }
    if (x < n) {
        p.push_back(x);
    }

    for (auto& i : p) cout << i << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        buildPermutationMaxColorX(n, x);
    }
    return 0;
}