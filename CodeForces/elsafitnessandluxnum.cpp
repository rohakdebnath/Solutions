#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 l, r; cin >> l >> r; --l;
    auto find = [&] (i64 x) ->i64 {
        i64 sx = sqrtl(x);
        return 3 * (sx - 1) + (sx * sx <= x) + (sx * sx + sx <= x) + (sx * sx + 2 * sx <= x);
    };
    cout << find(r) - find(l) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
