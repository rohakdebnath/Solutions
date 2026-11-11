#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<vector<vector<vector<int>>>> dp (n + 1, vector<vector<vector<int>>> (n + 1, vector<vector<int>> (n + 1, vector<int> (n + 1, inf))));
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < n; ++j) {
            dp[i][j][1][1] = grid[i][j] == '#';
        }
    }

    vector<vector<int>> rs(n, vector<int>(n + 1, 0));
    vector<vector<int>> cs(n, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rs[i][j + 1] = rs[i][j] + (grid[i][j] == '#');
            cs[i][j + 1] = cs[i][j] + (grid[j][i] == '#');
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[i][j][k][0] = dp[i][j][0][k] = 0;
            }
        }
    }

    for (int v = 1; v <= n; ++v) {
        for (int h = 1; h <= n; ++h) {
            for (int i = 0; i + v <= n; ++i) {
                for (int j = 0; j + h <= n; ++j) {
                    if (v == 1 and h == 1) continue;
                    dp[i][j][v][h] = max(v, h);
                    // vertical splits
                    for (int e = i; e < i + v; ++e) {
                        int white = rs[e][j + h] - rs[e][j];
                        if (white == 0 and e + 1 <= n) {
                            dp[i][j][v][h] = min(dp[i][j][v][h], dp[i][j][e - i][h] + dp[e + 1][j][v - (e - i + 1)][h]);
                        }
                    }
                    // horizontal splits
                    for (int e = j; e < j + h; ++e) {
                        int white = cs[e][i + v] - cs[e][i];
                        if (white == 0 and e + 1 <= n) {
                            dp[i][j][v][h] = min(dp[i][j][v][h], dp[i][j][v][e - j] + dp[i][e + 1][v][h - (e - j + 1)]);
                        }
                    }
                }
            }
        }   
    }
    cout << dp[0][0][n][n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
