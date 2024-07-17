#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1);
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + 1;
        if (a[i] + i < n) dp[i] = min(dp[i], dp[a[i] + 1 + i]);
    }
    cout << dp[0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
