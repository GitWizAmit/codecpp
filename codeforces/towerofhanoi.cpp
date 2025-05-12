#include<iostream>
using namespace std;


void towerOfHanoi(int n, int from, int to, int support) {
    if (n == 0) return;

    towerOfHanoi(n - 1, from, support, to);
    cout << from << " " << to << '\n';
    towerOfHanoi(n - 1, support, to, from);
}

int main() {
    int n;
    cin >> n;
    
    cout << (1 << n) - 1 << '\n';
    towerOfHanoi(n, 1, 3, 2);
    return 0;
}