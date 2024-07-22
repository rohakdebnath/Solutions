#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int m, x; cin >> m >> x;
    vector<i64> dp (1, 0); //max money left after buying j happiness
    int s = 0;
    for (int i = 0; i < m; ++i) {
        int h, c; cin >> c >> h;
        s += h;
        dp.resize(s + 1, -1);
        for (int j = s; j >= h; --j) {
            dp[j] = max(dp[j], dp[j - h] - c);
        }
        for (int j = 0; j <= s; ++j) {
            if (dp[j] >= 0) dp[j] += x;
        }
    }
    int ans = s;
    while (dp[ans] == -1) --ans;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
