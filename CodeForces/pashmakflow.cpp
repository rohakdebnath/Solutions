#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int x = a.end() - max_element(a.begin(), a.end());
    int y = a.rend() - min_element(a.rbegin(), a.rend());
    int ans = a[n - x] - a[y - 1];
    cout << ans << ' ';
    if (ans == 0) cout << 1LL * n * (n - 1) / 2 << '\n';
    else cout << 1LL * x * y << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
