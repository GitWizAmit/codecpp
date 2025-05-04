#include<iostream>
#include<set>
using namespace std; 

void solve() {

}

int main() {
    // Fast IO
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    set<char> st;
    for (char c : s) st.insert(c);
    for (char c = 'a'; c <= 'z'; c++) {
       if (st.find(c) == st.end()) {
        cout << c;
        break;
       }
    }
    return 0;
}