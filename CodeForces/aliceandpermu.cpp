#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, b, c; cin >> n >> b >> c;
    if (b == 0) {
        if (c < n - 2) {
            cout << "-1\n";
        } else {
            cout << n - (c < n) << '\n';
        }
    } else {
        if (c >= n) {
            cout << n << '\n';
        } else {
            cout << c + (n - c) / b * (b - 1) + (n - c) % b - ((n - c) % b > 0) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
