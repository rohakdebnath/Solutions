#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    int m = min(x, y);
    cout << "0 0 " << m << ' ' << m << '\n';
    cout << "0 " << m << ' ' << m << ' ' << "0\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
