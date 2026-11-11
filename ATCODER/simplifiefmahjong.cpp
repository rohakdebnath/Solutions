#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    i64 ans = 0;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    a.push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] > a[i]) {
            int y = (a[i - 1] - a[i] + 1) / 2;
            a[i - 1] -= 2 * y;
            if (a[i - 1] < 0) {
                a[i - 1] += 2;
                y -= 1;
            }
            ans += y;
        }
        if (a[i] >= a[i - 1]) {
            a[i] -= a[i - 1];
            ans += a[i - 1];
            a[i - 1] = 0;
        }
    }

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
