#include<bits/stdc++.h>
 
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
 
void print(vector<vector<char>>& ans) {
    for (auto& a : ans) {
        for (char c : a) cout << c;
        cout << '\n';
    }
}
 
void printSame(vector<vector<char>>& ans, vector<vector<char>>& v, int row, int col) {
    int x = 0;
    for (int i = 0; i < row && x < v.size(); ++i) {
        int y = 0;
        bool flag = false;
        for (int j = 0; j < col && y < v[x].size(); ++j) {
            if (ans[i][j] == '\0') {
                ans[i][j] = v[x][y];
                flag = true;
                y++;
            }
        }
        if (flag) x++;
    }
}
 
void printAllStar(vector<vector<char>>& ans, vector<vector<char>>& v, int row, int col) {
    int x = 0;
    for (int i = 0; i < row && x < v.size(); ++i) {
        int y = 0;
        bool flag = false;
        for (int j = 0; j < col && y < v[x].size(); ++j) {
            if (ans[i][j] == '\0') {
                ans[i][j] = '*';
                flag = true;
                y++;
            }
        }
        if (flag) x++;
    }
}
 
 
void rec(vector<vector<char>>& ref, vector<vector<char>>& v, int k, int n, int start) {
    if (k == 1) {
        print(ref);
        return;
    }
 
    int row = binpow(n, start);
    int col = row;
    vector<vector<char>> ans(row, vector<char>(col));
    for (int i = 0; i < ref.size(); ++i) {
        for (int j = 0; j < ref[i].size(); ++j) {
            if (ref[i][j] == '.') {
                printSame(ans, v, row, col);
            } else if (ref[i][j] == '*') {
                printAllStar(ans, v, row, col);
            }
        }
    }
    rec(ans, v, k - 1, n, start + 1);
}
 
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<vector<char>> ref(n, vector<char>(n));
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = s[j];
            ref[i][j] = s[j];
        }
    }
    rec(ref, v, k, n, 2);
    return 0;
}