#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<double> dp (1); //dp[i][j] = probablity of sum exactly = j till the ith roll
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<double> ndp (dp.size() + 6);
        dp.resize(dp.size() + 6);
        for (int j = ndp.size() - 1; j >= 1; --j) {
            for (int k = 1; k <= 6; ++k) {
                if (j - k >= 0) ndp[j] += dp[j - k] * 1 / 6;
            }
        }
        dp = std::move(ndp);
    }

    double ans = 0;
    for (int i = a; i <= b; ++i) {
        ans += dp[i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
