#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {  
    i64 w, b; cin >> w >> b;
    i64 l = -1, r = 1;
    while (r * (r + 1) <= 2 * (w + b)) r *= 2;
    while (r - l > 1) {
        i64 m = l + (r - l) / 2;
        if (m * (m + 1) <= 2 * (w + b)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
