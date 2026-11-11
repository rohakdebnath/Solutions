#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    i64 r = 0;
    for (int i = 0; i < n - 1; ++i) {
        int t = min(a[i + 1], max(0, a[i] + a[i + 1] - x));
        a[i + 1] -= t;
        r += t;
        if (a[i] + a[i + 1] > x) {
            t = a[i] - x;
            a[i] -= t;
            r += t;
        }
    }
    cout << r << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
//first attempt: greedy on picks (2nd element strictly better than first)

