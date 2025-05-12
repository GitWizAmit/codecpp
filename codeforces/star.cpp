#include<iostream>
using namespace std;


long long f(long long x) {
    return 6 * x * x - 6 * x + 1;
}

int main() {
    long long a;
    cin >> a;

    cout << f(a);
    return 0;
}