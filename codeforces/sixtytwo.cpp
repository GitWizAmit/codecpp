#include<iostream>
using namespace std;

void solve(int a[], int n) {
    while (next_permutation(a, a + n)) {
        int numerator = 0, denominator = 0;
        for (int i = 0; i < 5; ++i) {
            numerator = (numerator * 10) + a[i];
        }
        for (int i = 5; i < 10; ++i) {
            denominator = (denominator * 10) + a[i];
        }
        if (numerator == denominator * 62) {
            cout << numerator << " " << denominator << '\n';
        }
    }
}

int main() {
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    solve(a, 10);
    return 0;
}