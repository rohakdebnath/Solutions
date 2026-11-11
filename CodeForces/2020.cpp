#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 b, c, d; cin >> b >> c >> d;
    i64 a = 0;
    map<i64, i64> p;
    p[0] = 0;
    p[1] = 1;
    p[2] = 0;
    p[3] = -1;
    p[4] = -1;
    p[5] = 0;
    p[6] = 1;
    p[7] = 0;
    for (i64 i = 0; i < 62; ++i) {
        i64 q = 0;
        q |= ((d >> i) & 1LL) << 0LL, q |= ((c >> i) & 1LL) << 1LL, q |= ((b >> i) & 1LL) << 2LL;
        if (p[q] == -1) {
            cout << "-1\n";
            return;
        }
        a ^= (p[q] << i);
    }
    cout << a << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
//0101, 01, 0111

