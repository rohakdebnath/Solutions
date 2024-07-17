#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1); //dp[i] = disintegration time of ith flower
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i + 1] < a[i]) dp[i] = a[i];
        else {
            dp[i] = dp[i + 1] + 1;
        }
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
