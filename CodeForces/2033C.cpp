#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n / 2; ++i) {
        if (a[i] == a[i - 1] or a[n - i - 1] == a[n - i]) swap(a[i], a[n - 1 - i]);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (a[i] == a[i - 1]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
