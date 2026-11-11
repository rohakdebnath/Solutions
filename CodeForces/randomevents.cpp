#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int x = n;
    while (x > 0 and a[x - 1] == x) --x;

    double s = 1;
    for (int i = 0; i < m; ++i) {
        int r; 
        double p;
        cin >> r >> p;
        if (r < x or x == 0) continue;
        s *= (1 - p);
    }
    cout << fixed << setprecision(8) << (x == 0 ? 1 : 1 - s) << '\n';

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
