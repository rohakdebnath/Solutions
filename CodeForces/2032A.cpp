#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int z = 0, o = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int x; cin >> x;
        if (x) ++o;
        else ++z;
    }
    cout << n - z / 2 - o / 2 << ' ' << min(z, o) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
