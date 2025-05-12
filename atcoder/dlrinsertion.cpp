#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    deque<int> left, right;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'L') right.push_back(curr);
        else left.push_back(curr);
        curr = i + 1;
    }
    for (int i = 0; i < left.size(); ++i) cout << left[i] << " ";
    cout << curr << " ";
    for (int i = right.size() - 1; i >= 0; --i) cout << right[i] << " "; 

    return 0;
}