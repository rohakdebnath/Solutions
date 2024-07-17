#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    int ra = 0, rb = 0, both = 0;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) ra += a[i];
        else if (b[i] > a[i]) rb += b[i];
        else {
            if (a[i] == -1) --ra, --rb, ++both;
            else if (a[i] == 1) ++both;
        }
    }
    if (ra > rb) swap(ra, rb); //ra <= rb wlog
    int d = rb - ra;
    ra += min(both, d); both -= min(both, d);
    cout << min(ra, rb) + both / 2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
