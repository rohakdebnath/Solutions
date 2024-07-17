#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 sz = 1e6 + 1;
void solve() {
    i64 w, f; cin >> w >> f;
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    i64 s = accumulate(a.begin(), a.end(), 0LL);
    bitset<sz> dp;
    dp[0] = 1;
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = sz - 1; j >= a[i]; --j) {
            dp[j] = (dp[j - a[i]] or dp[j]);
        }
    }

    i64 ans = 2e9;
    for (int i = 0; i < sz; ++i) {
        if (dp[i]) ans = min(ans, max((i - 1) / w + 1, (s - i - 1) / f + 1));
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
