#include<iostream>
#include<vector>

using namespace std;

int binpow(int a, int b) {
    int result = 1;
    while (b) {
        if (b % 2) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = s[j];
        }
    }
    
    int size = binpow(n, k);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            char res = '.';
            bool found = false;
            for (int m = 0; m <= k; ++m) {
                int exponent = k - m;
                int divisor = binpow(n, exponent);
                int x = (i / divisor) % n;
                int y = (j / divisor) % n;
                if (v[x][y] == '*') {
                    res = '*';
                    found = true;
                    break;
                }
            }
            if (!found) {
                res = v[i % n][j % n];
            }
            cout << res;
        }
        cout << '\n';
    }
    return 0;
}