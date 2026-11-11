#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (m); for (int i = 0; i < m; ++i) cin >> b[i];
    vector<int> c (k); for (int i = 0; i < k; ++i) cin >> c[i];

    sort(a.begin(), a.end()), sort(b.begin(), b.end()), sort(c.begin(), c.end());

    int sec = 0, dis = 0, p = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] >= dis) {
            sec = dis;
            dis = a[i] - a[i - 1];
            p = i;
        } else if (a[i] - a[i - 1] > sec) sec = a[i] - a[i - 1]; 
    }
    int targ = (a[p] + a[p - 1]) / 2;
    for (int i = 0; i < m; ++i) {
        int t = upper_bound(c.begin(), c.end(), targ - b[i]) - c.begin() - 1;
        if (t >= 0) dis = min({dis, b[i] + c[t] - a[p - 1], a[p] - b[i] - c[t]});
        if (t + 1 < k) dis = min({dis, b[i] + c[t + 1] - a[p - 1], a[p] - b[i] - c[t + 1]});
    }
    cout << max(dis, sec) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
