//a b, c d, given a <= b and d <= c, curr = mod(a - c) + mod(b - d), i have to show that 
//mod(d - a) + mod(c - b) <= mod(a - c) + mod(b - d), which is obvious
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    array<array<i64, 1000>, 2> a;
    for (i64 i = 0; i < 1000; ++i) {
        cin >> a[0][i] >> a[1][i];
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    i64 ans = 0;
    for (i64 i = 0; i < 1000; ++i) {
        auto p = equal_range(a[1].begin(), a[1].end(), a[0][i]);
        ans += a[0][i] * (p.second - p.first);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

