#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b, k; cin >> a >> b >> k;
    i64 l = a - 1, r = b + 1;

    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (b / m >= k) l = m;
        else r = m;
    }
    cout << (l - a + 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
