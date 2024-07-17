#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s, t; cin >> s >> t;
    int l = s.size(), m = t.size();
    vector<vector<int>> dp (l + 1, vector<int> (m + 1));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = 1 + dp[i][j];
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[l][m] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; T = 1;
    while(T--) solve();
    return 0;
}
