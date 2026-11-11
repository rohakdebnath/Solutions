#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    i64 ans = 0;
    if (n % 2) {
        ans = 1e18;
        for (i64 i = 0; i < n; i += 2) {
            i64 res = 0;
            for (i64 j = 0; j < n; j += 2) {
                if (j == i) {
                    j--;
                    continue;
                }
                res = max(res, a[j + 1] - a[j]);
            }
            ans = min(ans, res);
        }
    } else {
        for (i64 i = 0; i < n; i += 2) {
            ans = max(ans, a[i + 1] - a[i]);
        }
    }
    cout << max(ans, 1LL) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
