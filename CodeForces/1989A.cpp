#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x, y; cin >> x >> y;
    cout << (y < -1 ? "NO\n" : "YES\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
