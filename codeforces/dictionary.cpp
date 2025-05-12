#include<iostream>
using namespace std;

int solve(string &s) {
    int first_ = s[0] - 'a';
    int second_ = s[1] - 'a';
    if (s[0] > s[1]) second_ += 1;

    return (25 * first_) + second_;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}