#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 1) {
        if (k == 1) {
            cout << "1\n1\n";
        } else cout << "-1\n";

        return;
    }
    if (n == k or n == 1) {
        cout << "-1\n";
        return;
    }

    if (k % 2) {
        cout << "5\n1 2 " << k << " " << k + 1 << " " << k + 2 << '\n';
    } else {
        cout << "3\n1 " << k << " " << k + 1 << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
