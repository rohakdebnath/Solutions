#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    i64 x, m; cin >> x >> m;
    m = min(m, (1LL << (64 - __builtin_clzll(x))) - 1);
    i64 ans = 0;

    for (i64 i = 1; i <= m; ++i) {
        i64 f = x ^ i;
        if (f != 0 and (x % f == 0 or i % f == 0)) ++ans;
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
