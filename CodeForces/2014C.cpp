#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 inf = 1e12;
void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    i64 sum = accumulate(a.begin(), a.end(), 0LL);

    auto check = [&] (i64 x) -> bool{
        double nsavg = (sum * 1.0 + x) / (2 * n);
        a[n - 1] += x;
        i64 i = lower_bound(a.begin(), a.end(), nsavg) - a.begin();
        a[n - 1] -= x;
        return i > n / 2;
    };
    i64 l = -1, r = inf;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << (r == inf ? -1: r) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
