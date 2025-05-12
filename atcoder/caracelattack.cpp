#include<iostream>

using namespace std;

#define int long long

int rec(int H) {
    if (H <= 0) return 0;
    if (H == 1) return 1;
    
    int attacks = 2 * rec(H / 2) + 1;

    return attacks;
}

signed main() {
    int H;
    cin >> H;
    cout << rec(H);
    return 0;
}