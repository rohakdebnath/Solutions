#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    auto lug = [&] (i64 x, i64 y) -> i64{
        i64 t = 0;
        if (x >= y) {
            while (y < x) {
                y = y * y;
                ++t;
            }
            return t;
        } else {
            if (x == 1) return 0;
            while (x * x <= y) {
                x = x * x;
                ++t;
            }
            return -t;
        }
    };
    vector<i64> dp (n); //dp[i] = operations required on the ith number
    for (i64 i = 1; i < n; ++i) {
        if (a[i] == 1 and a[i - 1] > 1) {
            cout << "-1\n";
            return;
        }
        dp[i] = max<i64>(0, dp[i - 1] + lug(a[i - 1], a[i]));
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
