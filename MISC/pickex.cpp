#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int x; cin >> x;
    sort(a.begin(), a.end());
    i64 s = accumulate(a.begin(), a.begin() + n - x + 1, 0LL);
    for (int i = n + 1 - x; i < n; ++i) {
        a[i] = min(a[i], s / (x - n + i));
        s += a[i];
    }
    cout << s - s % x << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

