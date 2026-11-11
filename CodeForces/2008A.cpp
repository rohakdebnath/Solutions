#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b; cin >> a >> b;
    // if (b % 2) {
    //     if (a > 1) {
    //         a -= 2;
    //         b += 1;
    //     } else {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    if (a & 1 or (a == 0 and b & 1)) cout << "NO\n";
    else cout << "YES\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
