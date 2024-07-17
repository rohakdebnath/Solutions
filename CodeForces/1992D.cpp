#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 2e18;
void solve() {
    i64 n, m, k; cin >> n >> m >> k;
    string s; cin >> s; s = 'L' + s + 'L';
    n += 2;
    vector<i64> dp (n, inf); //dp[i] = min water crosses required to cross ith segment
    dp[0] = 0;
    for (i64 i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            for (i64 j = 1; j <= m; ++j) {
                if ((i + j < n) and (s[i + j] != 'C')) {
                    dp[i + j] = min(dp[i + j], dp[i] + (s[i + j] == 'W'));
                }
            }
        } else if (s[i] == 'W' and s[i + 1] != 'C') {
            dp[i + 1] = min(dp[i + 1], dp[i] + (s[i + 1] == 'W'));
        }
    }
    cout << dp[n - 1] << '\n';
    cout << (dp[n - 1] <= k ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
