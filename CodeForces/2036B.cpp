#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (k);
    for (i64 i = 0; i < k; ++i) {
        i64 b, c; cin >> b >> c;
        --b;
        a[b] += c;
    }
    sort(a.begin(), a.end(), greater<i64> ());
    i64 ans = 0;
    for (i64 i = 0; i < min(n, k); ++i) {
        ans += a[i];
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
