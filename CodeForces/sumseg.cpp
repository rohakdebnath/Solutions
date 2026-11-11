#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> p (n + 1); partial_sum(a.begin(), a.end(), p.begin() + 1);
    vector<i64> pp (n + 1); partial_sum(p.begin(), p.end(), pp.begin());

    auto block = [&] (i64 x) { //number of blocks strictly less than x
        i64 l = -1, r = n + 1;
        while (r - l > 1) {
            i64 m = l + (r - l) / 2;
            if (n * m - m * (m - 1) /2 < x) l = m;
            else r = m;
        }
        return l;
    };  
    vector<i64> s (n + 1);
    for (i64 i = 1; i <= n; ++i) {
        s[i] = pp[n] - pp[i - 1] - p[i - 1] * (n - i + 1);
    }
    partial_sum(s.begin(), s.end(), s.begin());
    auto run = [&] (i64 x) -> i64 {
        i64 m = block(x);
        if (m == -1) return 0;
        i64 r = x - (n * m - m * (m - 1) / 2); // a_m+1, a_m+1 + a_m+2, .. s(m + 1, m + r)
        return s[m] + pp[m + r] - pp[m] - p[m] * r;
    };
    i64 q; cin >> q;
    while (q--) {
        i64 x, y; cin >> x >> y; --x;
        cout << run(y) - run(x) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
