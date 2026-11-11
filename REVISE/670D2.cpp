#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<i64> b (n); for (int i = 0; i < n; ++i) cin >> b[i];

    auto search = [&] (int m) -> bool {
        i64 x = k;
        for (int i = 0; i < n; ++i) {
            if (b[i] - m * a[i] < 0) x += b[i] - m * a[i];
            if (x < 0) return false;
        }
        return true;
    };

    int l = 0, r = 2e9 + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (search(m)) l = m;
        else r = m;
    }

    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
