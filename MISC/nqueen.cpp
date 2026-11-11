#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class Solution {
private:
    vector<string> board;
    long long solutions = 0;

    void nqueen(int n, int i, vector<int>& rule) {
        if (i == n) {
            solutions++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (rule[j] == 0) {
                int old_rule_j = rule[j];
                rule[j] = 7;  // 0b111
                board[i][j] = 'Q';

                vector<int> newrule(n, 0);
                for (int k = 0; k < n; k++) {
                    if (k - 1 >= 0 && ((rule[k - 1] >> 0) & 1)) {
                        newrule[k] |= (1 << 0);
                    }
                    if (((rule[k] >> 1) & 1)) {
                        newrule[k] |= (1 << 1);
                    }
                    if (k + 1 < n && ((rule[k + 1] >> 2) & 1)) {
                        newrule[k] |= (1 << 2);
                    }
                }

                nqueen(n, i + 1, newrule);

                board[i][j] = '.';
                rule[j] = old_rule_j;
            }
        }
    }

public:
    long long solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        solutions = 0;
        vector<int> rule(n, 0);
        nqueen(n, 0, rule);
        return solutions;
    }
};

int main() {
    int n, d;
    cin >> n >> d;

    auto start = high_resolution_clock::now();

    Solution sol;
    long long total_solutions = sol.solveNQueens(n);

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "n = " << n << "\n";
    cout << "frontier_depth = " << d << "\n";
    cout << "solutions = " << total_solutions << "\n";
    cout << fixed << setprecision(6);
    cout << "time_taken = " << elapsed.count() << " seconds\n";

    return 0;
}
