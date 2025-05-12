#include<iostream>
using namespace std;

void solve(int q, string& s) {
    deque<char> dq;
    for (auto& c : s) dq.push_back(c);
    int is_flipped = 0;
    while (q--) {
        int k;
        cin >> k;
        if (k == 2) {
            int f;
            char c;
            cin >> f >> c;
            if (is_flipped) {
                if (f == 2) dq.push_front(c);
                else dq.push_back(c);
            } else {
                if (f == 2) dq.push_back(c);
                else dq.push_front(c);
            }
        } else {
            if (is_flipped) is_flipped = 0;
            else is_flipped = 1;
        }
    }
    if (is_flipped) {
        for (auto it = dq.rbegin(); it != dq.rend(); ++it) cout << *it;
    } else {
        for (auto it = dq.begin(); it != dq.end(); ++it) cout << *it;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    int q;
    cin >> s >> q;
    solve(q, s);

    return 0;
}