#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 1e15;
void solve() {
    i64 n, l, r; cin >> n >> l >> r;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> dp (n + 1, -inf); //dp[i] = max points you can get till rounds i
    vector<i64> p (n, -1); //p[i] = j means for the sequence ending at i, j is the beginning of the segment such that sum[j..i] is just >= l and <= r, -1 if doesnt exist

    i64 j = n - 1, s = 0;
    for (i64 i = n - 1; i >= 0; --i) {
        while (j >= 0 and s < l) {
            s += a[j--];
        }
        if (l <= s and s <= r) {
            p[i] = j + 1;
        }
        s -= a[i];
    }
    dp[0] = 0;
    for (i64 i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (p[i] == -1) continue;
        dp[i + 1] = max(dp[i + 1], dp[p[i]] + 1);
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
