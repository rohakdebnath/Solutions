#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b, n; cin >> a >> b >> n;
    for (int i = 0; i < 10; ++i) {
        int x = 10 * a + i;
        if (x % b == 0) {
            cout << x;
            for (int j = 0; j < n - 1; ++j) {
                cout << '0';
            }
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
