#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int W = 30;
void solve() {
    int n; cin >> n;
    vector<int> dp (W + 1); //dp[i] = maximum price you can buy with i weights
    for (int i = 0; i < n; ++i) {
        int p, w; cin >> p >> w;
        for (int j = W; j >= 0; --j) {
            if (j - w >= 0) dp[j] = max(dp[j], dp[j - w] + p);
        }
    }
    i64 ans = 0;
    int q; cin >> q;
    while(q--) {
        int f; cin >> f;
        ans += dp[f];
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
