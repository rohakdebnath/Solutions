#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    int m = 0, j = 0, s = t;
    for (int i = 0; i < n; ++i) {
        while (j < n and s >= a[j]) {
            s -= a[j];
            ++j;
        }
        m = max(m, j - i);
        if (j > i) s += a[i];
        else ++j;
    }
    cout << m << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

