//three operations allowed, delete costs 2 points, replace costs 1 point, doing nothing is 0 and need to make the string alternating.
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = inf;
    for (int i = 0; i < 26; ++i) { // ijijij ahh string
        for (int j = 0; j < 26; ++j) {
            vector<vector<int>> dp (n + 1, vector<int> (2, inf)); //dp[i][j] = minimum cost to convert prefix i to alt string of parity j
            dp[0][0] = 0;
            for (int k = 0; k < n; ++k) {
                if (s[k] == char('a' + i)) dp[k + 1][1] = min(dp[k + 1][1], dp[k][0]);
                if (s[k] == char('a' + j)) dp[k + 1][0] = min(dp[k + 1][0], dp[k][1]);
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        dp[k + 1][x] = min(dp[k + 1][x], dp[k][y] + 1 + (x == y));
                    }
                }
            }
            ans = min(ans, dp[n][0]);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
