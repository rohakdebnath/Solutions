#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 1e12;
void solve() {
    i64 n, x; cin >> n >> x;
    vector<i64> a (n), p (n), b (n), q (n);

    for (i64 i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        if (a[i] * q[i] > b[i] * p[i] or (a[i] * q[i] == b[i] * p[i] and a[i] < b[i])) { // always b is a better machine
            swap(a[i], b[i]);
            swap(p[i], q[i]);
        } 
    }

    auto check = [&] (i64 m) -> bool {
        i64 c = 0;
        for (i64 i = 0; i < n; ++i) {
            i64 l = lcm(a[i], b[i]); // amount of a[i] used is <= l / a[i]. goal: make atleast m using a and b with min cost
            i64 z = inf;
            for (i64 j = 0; j <= min(m, l / a[i]); ++j) {
                i64 t = 0, y = m;
                t += j * p[i];
                y -= j * a[i];
                t += (y + b[i] - 1) / b[i] * q[i];
                z = min(z, t);
            }
            c += z;
            if (c > x) return false;
        }
        return true;
    };
    i64 l = 0, r = 1;
    while (check(r)) r *= 2;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
