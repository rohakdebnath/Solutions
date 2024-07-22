#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, t, p; cin >> n >> t >> p;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int x = lower_bound(a.begin(), a.end(), t) - a.begin();
    int d = x - (n - p);
    if (d <= 0) {
        cout << "0\n";
        return;
    }
    cout << t - a[n - p] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
