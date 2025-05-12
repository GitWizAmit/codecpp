#include<iostream>
#include<iomanip>

using namespace std;

int nCr(int n, int r) {
    int res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

double solve(string &s1, string &s2) {
    int actual_loc = 0, expected_loc = 0, unrecognized_count = 0;
    for (int i = 0; i < s1.length(); ++i) actual_loc += (s1[i] == '+' ? 1 : -1);
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] == '+') expected_loc += 1;
        if (s2[i] == '-') expected_loc -= 1;
        if (s2[i] == '?') unrecognized_count++;
    }

    // already met
    if ((actual_loc == expected_loc) && unrecognized_count == 0) return 1;
    
    int diff = actual_loc - expected_loc;
    int mul = (diff < 0) ? -1 : 1;
    int total_rem_permutation = 1 << unrecognized_count;

    double ans = 0;
    for (int i = 1; i <= unrecognized_count; ++i) {
        int mul2 = (mul == 1) ? -1 : 1;
        int val = (mul * i) + (unrecognized_count - i) * mul2;
        if (val == diff) {
            ans += nCr(unrecognized_count, i);
        }
    }

    return ans / total_rem_permutation;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    double result = solve(s1, s2);
    cout << fixed << setprecision(12) << result << endl;

    return 0;
}