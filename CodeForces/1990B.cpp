#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x, y; cin >> n >> x >> y; --x, --y;
    vector<int> a (n, 1);
    for (int i = x + 1; i < n; i += 2) {
        a[i] = -1;
    }
    for (int i = y - 1; i >= 0; i -= 2) {
        a[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
