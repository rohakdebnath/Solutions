#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int solve(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    //dp[i][j] length of the lis starting from (i, j)
    vector<vector<int>> dp (n, vector<int> (m, -1));
    auto dfs = [&] (auto&& self, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        int l = 1;
        for (int d = 0; d < 4; ++d) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and g[i][j] < g[nx][ny]) l = max(l, 1 + self(self, nx, ny));
        }
        return dp[i][j] = l;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dfs(dfs, i, j));
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << solve(m) << '\n';
    return 0;
}

    vector<vector<int>> m = {{3, 4, 5},{3,2, 6},{2,2,1}};
