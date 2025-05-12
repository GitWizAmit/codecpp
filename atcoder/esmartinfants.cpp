#include<iostream>
#include<set>

using namespace std;

unordered_map<int,int> infant_rating;
unordered_map<int,set<int>> kindergarten_infant;
unordered_map<int,int> infant_kindergarten;
multiset<int> max_rating_kindergarten;

unordered_map<int,multiset<int>> mapKindergartenWithRating() {
    unordered_map<int,multiset<int>> kindergarten_rating;
    for (auto& it : kindergarten_infant) {
        for (int s : it.second) {
            kindergarten_rating[it.first].insert(infant_rating[s]);
        }
    }
    return kindergarten_rating;
}

void createMaxRatingForEachKindergarten(unordered_map<int,multiset<int>>& kindergarten_rating) {
    for (auto& [k, s] : kindergarten_rating) {
        max_rating_kindergarten.insert(*s.rbegin());
    }
}

void solve(int q) {
    unordered_map<int,multiset<int>> kindergarten_rating = mapKindergartenWithRating();
    createMaxRatingForEachKindergarten(kindergarten_rating);
    while (q--) {
        int c, d;
        cin >> c >> d;
        int rating_initial = infant_rating[c];
        int kindergarten_initial = infant_kindergarten[c];
       
        auto it = kindergarten_rating[kindergarten_initial].find(rating_initial);
        
        infant_kindergarten[c] = d;

        cout << *max_rating_kindergarten.begin() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        infant_rating[i] = a;
        kindergarten_infant[b].insert(i);
        infant_kindergarten[i] = b;
    }
    solve(q);
    return 0;
}