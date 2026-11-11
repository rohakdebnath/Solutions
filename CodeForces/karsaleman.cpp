#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, x; cin >> n >> x;
    x = min(x, n);
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cout << max(a[n - 1], (accumulate(a.begin(), a.end(), 0LL) + x - 1) / x) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
