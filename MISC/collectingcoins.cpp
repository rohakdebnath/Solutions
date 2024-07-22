#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    map<int, int> h, v, db, df;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        ++h[y], ++v[x], ++db[y - x], ++df[y + x];
        m = max({m, h[y], v[x], db[y - x], df[y + x]});
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
