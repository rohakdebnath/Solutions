#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    if (n % 2) { //cant be more than n since last op is and 
        // 1 3 n - 1 n
        cout << n << '\n';
        for (int i = 1; i <= n; ++i) {
            if (i != 1 and i != 3 and i != n and i != n - 1) {
                cout << i << ' ';
            }
        }
        cout << "1 3 " << n - 1 << ' ' << n << '\n';
    } else { //can be equal to the or of everything, last op is or
        // pow of 2 : 1 3 n - 2 n - 1 n 
        // not a pow of 2 : 1 3 h - 1
        int x = 1 << (64 - __builtin_clzll(n) - 1);
        cout << (x << 1) - 1 << '\n';
        if ((n & (n - 1)) == 0) {
            for (int i = 1; i <= n; ++i) {
                if (i != 1 and i != 3 and i != n - 2 and i != n - 1 and i != n) {
                    cout << i << ' ';
                }
            }
            cout << "1 3 " << n - 2 << ' ' << n - 1 << ' ' << n << '\n';
        } else {
            for (int i = 1; i <= n; ++i) {
                if (i != n and i != n - 1 and i != x - 1) {
                    cout << i << ' ';
                }
            }
            cout << n << ' ' << n - 1 << ' ' << x - 1 << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
