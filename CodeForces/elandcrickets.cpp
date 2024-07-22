#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> r (3), c (3);
    for (int i = 0; i < 3; ++i) {
        cin >> r[i] >> c[i];
    }
    int x, y; cin >> x >> y;
    auto centre = [&] (vector<int>& v) -> int {
        vector<int> f (n + 1);
        int rt = -1, mf = 0;
        for (int i = 0; i < 3; ++i) {
            ++f[v[i]];
            if (f[v[i]] > mf) {
                mf = f[v[i]];
                rt = v[i];
            }
        }
        return rt;
    };
    pair<int, int> cent = {centre(r), centre(c)};
    if (cent == make_pair(1, 1) or cent == make_pair(1, n) or cent == make_pair(n, n) or cent == make_pair(n, 1)) {
        cout << (x == cent.first or y == cent.second ? "YES\n": "NO\n");
    } else {
        if ((cent.first + cent.second) % 2 != (x + y) % 2 or (cent.first % 2 == x % 2 and cent.second % 2 == y % 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
