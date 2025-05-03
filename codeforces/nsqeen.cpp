#include<bits/stdc++.h>
using namespace std; 

int n;
int ans = 0;
vector<int> v;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool isAtKnightMove(int x1, int y1, int x2, int y2) {
    int xTwoBack = x1 - 2, xTwoFront = x1 + 2;
    int yOneLeft = y1 - 1, yOneFront = y1 + 1;
    int xOneBack = x1 - 1, xOneFront = x1 + 1;
    int yTwoLeft = y1 - 2, yTwoFront = y1 + 2;

    return (isValid(xTwoBack, yOneLeft) && xTwoBack == x2 && yOneLeft == y2)
            || (isValid(xTwoBack, yOneFront) && xTwoBack == x2 && yOneFront == y2)
            || (isValid(xTwoFront, yOneLeft) && xTwoFront == x2 && yOneLeft == y2)
            || (isValid(xTwoFront, yOneFront) && xTwoFront == x2 && yOneFront == y2)
            || (isValid(xOneBack, yTwoLeft) && xOneBack == x2 && yTwoLeft == y2)
            || (isValid(xOneBack, yTwoFront) && xOneBack == x2 && yTwoFront == y2)
            || (isValid(xOneFront, yTwoLeft) && xOneFront == x2 && yTwoLeft == y2)
            || (isValid(xOneFront, yTwoFront) && xOneFront == x2 && yTwoFront == y2);
}

bool check(int row, int col) {
    for (int prow = 0; prow < row; ++prow) {
        int pcol = v[prow];
        if (pcol == col || abs(prow - row) == abs(pcol - col)
                        || isAtKnightMove(prow, pcol, row, col)) return false;
    }
    return true;
}

void rec(int level) {
    if (level == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check(level, i)) {
            v.push_back(i);
            rec(level + 1);
            v.pop_back();
        }
    }
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    rec(0);
    cout << ans;
    return 0;
}