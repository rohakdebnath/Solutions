#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> lis (n), lds (n);
    for (int i = n - 1; i >= 0; --i) {
        lis[i] = 1;
        lds[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) lis[i] = max(lis[i], lis[j] + 1);
            if (a[j] < a[i]) lds[i] = max(lds[i], lds[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, lis[i] + lds[i] - 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
