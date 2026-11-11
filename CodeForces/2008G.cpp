#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    i64 g = 0;
    vector<i64> a (n); 
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    if (n == 1) {
        if (k > a[0]) cout << k << '\n';
        else cout << k - 1 << '\n';
        return;
    }
    if (g == 1) {
        cout << k + n - 1 << '\n';
        return;
    }
    i64 mex = 0;
    if (k > (g - 1) * (n - 1)) {
        mex += k - (g - 1) * (n - 1) + 1;
        k = (g - 1) * (n - 1);
    }
    i64 x = (k - 1) / (g - 1) + 1;
    i64 p = k - (x - 1) * (g - 1);
    mex += (x - 1) * g + p;
    cout << mex << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
