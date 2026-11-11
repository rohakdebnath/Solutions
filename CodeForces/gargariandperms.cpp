#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void chmax(int& a, int b) {
    a = max(a, b);
}
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> grid (k, vector<int> (n));
    vector<vector<int>> pos (k, vector<int> (n + 1)); //pos[i][j] = position of j in the ith perm
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            pos[i][grid[i][j]] = j;
        }
    }
    vector<int> dp (n + 1, 1); //dp[i] = length of the LCS ending at i. 
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            bool srv = true;
            for (int t = 1; t < k; ++t) {
                srv &= (pos[t][grid[0][j]] < pos[t][grid[0][i]]);
            }
            if (srv) {
                chmax(dp[grid[0][i]], dp[grid[0][j]] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
