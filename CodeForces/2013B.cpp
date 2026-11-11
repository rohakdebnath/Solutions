#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    cout << accumulate(a.begin(), a.end(), 0LL) - 2 * a[n - 2] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
