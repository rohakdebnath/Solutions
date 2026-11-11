#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    auto check = [&] (i64 m) -> i64 {
        vector<int> dp (n);
        dp[0] = a[0] >= m ? 1 : -1;
        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                dp[i] = max(dp[i - k], (a[i] >= m ? 1 : -1));
            } else {
                dp[i] = dp[i - 1] + (a[i] >= m ? 1 : -1);
                if (i >= k) {
                    dp[i] = max(dp[i - k], dp[i]);
                }
            }
        }
        return dp[n - 1] > 0;
    };
    i64 l = 1, r = 2;
    while (check(r)) r *= 2, l *= 2;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
