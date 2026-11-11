#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> d (n); for (int i = 0; i < n; ++i) cin >> d[i];

    auto f = [&] (int m) {
        i64 count = 0;
        i64 sum = 0;
        for (int i = 0; i < n; ++i) {
            if (m <= a[i]){
                i64 t = (a[i] - m) / d[i] + 1;
                count += t;
                sum += t * (2 * a[i] - (t - 1) * d[i]) / 2;
            }
        }
        return pair{count, sum};
    };

    i64 l = 0, r = 1;
    while (f(r).first > k) r *= 2;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m).first <= k) r = m;
        else l = m;
    }
    i64 ans = f(r).second;
    if (r > 0) ans += (k - f(r).first) * (r - 1);

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
