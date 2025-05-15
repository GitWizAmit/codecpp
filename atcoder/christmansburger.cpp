#include<iostream>
#include<unordered_map>

using namespace std;
#define int long long
#define endl '\n'

// Total size of each layer
unordered_map<int, int> total_length;

// Total number of 'P' in each layer
unordered_map<int, int> p_count;

void precompute() {
    total_length[0] = 1;
    p_count[0] = 1;
    for (int i = 1; i <= 50; i++) {
        total_length[i] = total_length[i - 1] * 2 + 3;
        p_count[i] = p_count[i - 1] * 2 + 1;
    }
}

int count_p(int n, int x) {
    if (n == 0) return 1;
    if (x == 1) return 0;

    if (x <= 1 + total_length[n - 1]) return count_p(n - 1, x - 1);
    if (x == 2 + total_length[n - 1]) return p_count[n - 1] + 1;
    if (x > 2 + total_length[n - 1]) return count_p(n - 1, x - (2 + total_length[n - 1])) + p_count[n - 1] + 1;
}

signed main() {
    // Fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, x;
    cin >> n >> x;
    precompute();
    cout << count_p(n, x) << endl;
    return 0;
}