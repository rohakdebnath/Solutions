#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s, p; cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<vector<int>> dp (n + 1, vector<int> (m + 1)); //dp[i][j] = number of ways to match prefix of length i and j or the respective strings
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        if (p[i] == '*') dp[0][i + 1] = dp[0][i - 1];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == p[j] or p[j] == '.') {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (p[j] == '*') {
                dp[i + 1][j + 1] = dp[i + 1][j - 1];
                char prev = p[j - 1];\
                if (prev == '.' or prev == s[i]) dp[i + 1][j + 1] += dp[i][j + 1];
            }
        }
    }

    cout << dp[n][m] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

