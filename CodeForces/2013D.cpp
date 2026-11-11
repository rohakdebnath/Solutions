#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];

    auto checkmax = [&] (i64 x) { //if all the elements can be made atleast x
        i64 s = 0;
        for (i64 i = 0; i < n; ++i) {
            i64 y = a[i] + s;
            if (y < x) return false;
            s += a[i] - x;
        }
        return true;
    };

    auto checkmin = [&] (i64 x) { //if all the elements can be made atmost x 
        i64 s = 0;
        for (i64 i = n - 1; i >= 0; --i) {
            i64 y = a[i] - s;
            if (y > x) return false;
            s += x - a[i];
        }
        return true;
    };

    i64 l = 0, r = a[0] + 1;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (checkmax(m)) l = m;
        else r = m;
    }
    i64 mn = l;

    l = a[n - 1] - 1, r = *max_element(a.begin(), a.end());
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (checkmin(m)) r = m;
        else l = m;
    }
    i64 mx = r;
    cout << mx - mn << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
