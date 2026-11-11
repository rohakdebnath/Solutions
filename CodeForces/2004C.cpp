#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<i64> ());
    for (i64 i = 1; i < n; i += 2) {
        i64 x = min(a[i - 1] - a[i], k);
        a[i] += x;
        k -= x;
    }
    i64 d = 0;
    for (i64 i = 0; i < n; ++i) {
        if (i % 2) d -= a[i];
        else d += a[i];

    }
    cout << d << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
