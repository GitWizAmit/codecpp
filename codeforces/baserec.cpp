#include<iostream>
using namespace std;

void recursion(int n) {
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    cout << n << '\n';
    recursion(n - 1);
    cout << n << '\n';
}

int main() {
    int n;
    cin >> n;
    recursion(n);
    return 0;
}