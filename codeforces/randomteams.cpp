#include<iostream>
using namespace std;

#define ll long long

void solve(ll n, ll m) {
    ll max = ((n - m + 1) * (n - m)) / 2;

    ll min_dis = n / m;
    ll rem = n - (min_dis * m);
    ll prod1 = ((min_dis - 1) * min_dis) / 2;
    ll prod2 = ((min_dis + 1) * min_dis) / 2;
    ll first_allot = prod2 * rem;
    ll second_allot = (m - rem) * prod1;

    ll min = first_allot + second_allot;

    cout << min << " " << max;
}

int main() {
    ll n, m;
    cin >> n >> m;
    solve(n, m);

    return 0;
}