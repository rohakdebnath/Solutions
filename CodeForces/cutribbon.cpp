#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    array<int, 3> a; for (int i = 0; i < 3; ++i) cin >> a[i];

    vector<int> dp (n + 1, -inf); //dp[i] = max cuts you can get for length i
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i - a[j] >= 0) dp[i] = max(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
