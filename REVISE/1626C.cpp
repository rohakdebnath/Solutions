#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> k (n), h (n); 
    for (i64 i = 0; i < n; ++i) cin >> k[i];
    for (i64 i = 0; i < n; ++i) cin >> h[i];

    vector<i64> dp (n); //dp[i] = min height to start from index i and kill all monsters till index n - 1
    dp[n - 1] = h[n - 1];
    for (i64 i = n - 2; i >= 0; --i) {
        dp[i] = max(h[i], dp[i + 1] - k[i + 1] + k[i]);
    }
    i64 ans = dp[0] * (dp[0] + 1) / 2, s = dp[0];
    for (i64 i = 1; i < n; ++i) {
        if (k[i] - k[i - 1] >= dp[i]) {
            ans += dp[i] * (dp[i] + 1) / 2;
            s = dp[i];
        } else {
            i64 x = s + (k[i] - k[i - 1]);
            ans += x * (x + 1) / 2 - s * (s + 1) / 2;
            s = x;
        }
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
