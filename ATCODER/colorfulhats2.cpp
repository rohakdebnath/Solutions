#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); 
    vector<i64> f (n), m (n);
    i64 init = 3;
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) m[i] = init--;
    }
    for (i64 i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++f[a[i]];
        } else {
            m[i] = f[a[i] - 1] - f[a[i]];
            ++f[a[i]];
        }
    }
    i64 ans = 1;
    for (i64 i = 0; i < n; ++i) {
        ans = (ans * m[i]) % mod;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
