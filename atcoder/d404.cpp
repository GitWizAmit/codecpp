#include<iostream>
#include<set>
using namespace std; 

void solve(vector<vector<int>>& zoo_animal, vector<int>& zoos, vector<int>& fee, int m) {
    unordered_map<int, int> seen_count; // animal -> times seen
    int total_fee = 0;
    int total_seen = 0;

    for (int zoo : zoos) {
        bool visit = false;
        for (int animal : zoo_animal[zoo]) {
            if (seen_count[animal] < 2) {
                visit = true;
                break;
            }
        }
        if (!visit) continue;

        // Visit zoo
        total_fee += fee[zoo - 1];

        for (int animal : zoo_animal[zoo]) {
            if (seen_count[animal] < 2) {
                seen_count[animal]++;
                total_seen++;
            }
        }

        if (total_seen == 2 * m) break; // Each of m animals seen twice
    }
    cout << total_fee;
}

int main() {
    // Fast IO
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> fee(n);
    for (int i = 0; i < n; ++i) cin >> fee[i];
    vector<vector<int>> zoo_animal(n + 1);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            zoo_animal[a].push_back(i + 1);
        }
    }

    vector<int> zoos;
    for (int i = 1; i <= n; ++i) zoos.push_back(i);

    // Custom sort: first by animal count desc, then fee asc
    sort(zoos.begin(), zoos.end(), [&](int a, int b) {
        int ac = zoo_animal[a].size();
        int bc = zoo_animal[b].size();
        if (ac != bc) return ac > bc;
        return fee[a - 1] < fee[b - 1];
    });
    for (int z : zoos) {
        cout << "zoo number is " << z << " and count is " << zoo_animal[z].size() << '\n';
    }

    solve(zoo_animal, zoos, fee, m);
    return 0;
}