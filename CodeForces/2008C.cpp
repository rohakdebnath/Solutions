#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 l, r; cin >> l >> r;
    r -= l;
    i64 a = 0, b = 1e8;
    while (b - a > 1) {
        i64 m = a + (b - a) / 2;
        if (m * (m + 1) <= 2 * r) a = m;
        else b = m;
    }
    cout << a + 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
