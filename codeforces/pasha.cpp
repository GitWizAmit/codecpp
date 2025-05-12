#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n / 4;
    cout << (n % 2 != 0 ? 0 : (n % 4 == 0 ? ans - 1 : ans));

    return 0;
}