#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int m, c; cin >> m >> c;
    vector<int> dp (m + 1); //dp[i] = 1, if you can spend i money or not
    dp[0] = 1;
    for (int _ = 0; _ < c; ++_) {
        int x; cin >> x;
        vector<int> p (x);
        for (int i = 0; i < x; ++i) {
            cin >> p[i];
        }
        decltype(dp) ndp (m + 1);
        for (int j = 0; j < x; ++j) {
            for (int i = m; i >= 0; --i) {
                if (i - p[j] >= 0) ndp[i] = dp[i - p[j]] or ndp[i];
            }
        }
        dp = ndp;
    }   
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        if (dp[i]) ans = i;
    }
    if (ans == 0) cout << "no solution\n";
    else cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
