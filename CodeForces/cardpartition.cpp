#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    i64 s = accumulate(a.begin(), a.end(), 0LL);
    i64 m = *max_element(a.begin(), a.end());

    for (i64 i = n; i >= 1; --i) {
        if ((s + k) % i > k) continue;
        if ((s + k) / i >= m) {
            cout << i << '\n';
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
