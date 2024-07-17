#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n); partial_sum(a.begin(), a.end(), p.begin());
    for (int i = 0; i < n; ++i) {
        cout << p[n - 1] - p[i] - (n - 1 - i) * a[i] + i * a[i] - (i - 1 >= 0 ? p[i - 1] : 0) - max(a[n - 1] - a[i], a[i] - a[0]) << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
