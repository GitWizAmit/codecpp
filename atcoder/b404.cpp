#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to rotate a grid 90 degrees clockwise
vector<vector<char>> rotate90(const vector<vector<char>>& grid, int N) {
    vector<vector<char>> rotated(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            rotated[j][N - 1 - i] = grid[i][j];
    return rotated;
}

int countDifferences(const vector<vector<char>>& A, const vector<vector<char>>& B, int N) {
    int diff = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (A[i][j] != B[i][j])
                ++diff;
    return diff;
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(N, vector<char>(N));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j)
            S[i][j] = row[j];
    }

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j)
            T[i][j] = row[j];
    }

    int min_ops = N * N + 3;

    vector<vector<char>> current = S;
    for (int r = 0; r < 4; ++r) {
        int flips = countDifferences(current, T, N);
        int total_cost = r + flips;
        min_ops = min(min_ops, total_cost);
        current = rotate90(current, N);
    }

    cout << min_ops << endl;
    return 0;
}
