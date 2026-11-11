#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (x + 1, inf); //dp[i] = min elements required to reach i
    dp[0] = 0;

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << dp[x] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
