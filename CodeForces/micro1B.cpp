#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    // maybe greedy will work here
    //first take the remaining shit from last day, then fill the garbage bags till u can fill them fully, leave the last one for next day
    i64 ans = 0, b = 0;
    for (i64 i = 0; i < n; ++i) {
        if (b) {
            a[i] -= min(a[i], k - b);
            ++ans;
        }
        ans += a[i] / k;
        a[i] %= k;
        b = a[i];
    }
    if (a[n - 1]) ++ans;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
