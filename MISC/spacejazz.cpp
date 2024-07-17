#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp (n + 1, vector<int> (n + 1)); //dp[i][j] = min insertions to make substring i..j space jazzy, 0 based and inclusive indexes, dp[i][j] for i > j is automatically 0
    for (int d = 0; d <= n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            dp[i][i + d] = dp[i + 1][i + d] + 1; //dont match with anyone insert just after and add the answer for the rest of the substring
            for (int j = i + 1; j <= i + d; ++j) {
                if (s[i] == s[j]) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i + 1][j - 1] + dp[j + 1][i + d]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
