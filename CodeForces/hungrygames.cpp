#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    vector<int> dp (n);
    i64 ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int x = upper_bound(p.begin() + i, p.end(), p[i] + k) - p.begin();
        int j = x - i - 1;
        dp[i] = j;
        if (x - i < n) dp[i] += dp[x - i];
        ans += dp[i];
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
