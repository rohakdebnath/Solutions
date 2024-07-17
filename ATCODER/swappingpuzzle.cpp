#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    // Input grids A and B
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }

    // Create grid C to store absolute differences
    vector<vector<int>> C(H, vector<int>(W));

    // Calculate absolute differences
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            C[i][j] = abs(A[i][j] - B[i][j]);
        }
    }

    // Check the pattern in rows and count 1s
    int total_swaps = 0;
    for (int i = 0; i < H; i++) {
        int sum = accumulate(C[i].begin(), C[i].end(), 0);
        if (sum % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
        total_swaps += sum / 2; // Count swaps needed for the row
    }

    // Check the pattern in columns and count 1s
    for (int j = 0; j < W; j++) {
        int sum = 0;
        for (int i = 0; i < H; i++) {
            sum += C[i][j];
        }
        if (sum % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
        total_swaps += sum / 2; // Count swaps needed for the column
    }

    // If both row and column patterns are satisfied, print the total swaps needed
    cout << total_swaps << endl;

    return 0;
}
