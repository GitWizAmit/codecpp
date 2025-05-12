#include<iostream>
#include<unordered_map>
#include<stack>
#include<algorithm>

using namespace std;

unordered_map<int, stack<int>> create_map(int arr1[], int arr2[], int m) {
    unordered_map<int, stack<int>> map;
    for (int i = 0; i < m; ++i) map[arr1[i]].push(arr2[i]);
    return map;
}

void solve(int a1[], int a2[], int m) {
    int temp_a2[m];
    for (int i = 0; i < m; ++i) temp_a2[i] = a2[i];
    sort(a1, a1 + m, greater<int>());
    sort(temp_a2, temp_a2 + m);

    unordered_map<int, stack<int>> map = create_map(temp_a2, a1, m);
    
    for (int i = 0; i < m; ++i) {
        int val = a2[i];
        stack<int>& st = map.at(a2[i]);
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m;
    cin >> m;

    int a1[m], a2[m];
    for (int i = 0; i < m; ++i) cin >> a1[i];
    for (int i = 0; i < m; ++i) cin >> a2[i];
    
    solve(a1, a2, m);
    return 0;
}