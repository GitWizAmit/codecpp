#include<iostream>
#include<map>
using namespace std;

void solve(int n) {
    map<string,int> om;
    int max_ = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        om[s]++;
        max_ = max(om[s], max_);
    }
    for (auto& it : om) {
        if (it.second == max_) {
            cout << it.first << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    solve(n);
    return 0;
}