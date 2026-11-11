#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, q; cin >> n >> q;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    auto f = [&] (i64 c, i64 x) -> i64{
        //returns the prefix sum[x] of the cth shift
        if (x <= n - c) {
            return p[c + x] - p[c];
        } else {
            return p[n] - p[c] + p[x - (n - c)];
        }
    };
    auto calc = [&] (i64 x) {
        i64 ans = x / n * f(1, n - 1);
        if (x % n == 0) return ans;
        ans += f((x + n - 1) / n - 1, x % n - 1);
        return ans;
    };
    while (q--) {
        i64 l, r; cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
