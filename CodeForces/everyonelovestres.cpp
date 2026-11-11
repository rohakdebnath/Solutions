#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    if (n == 1 or n == 3) {
        cout << "-1\n";
        return;
    }
    if (n % 2) {
        for (int i = 0; i < n - 5; ++i) {
            cout << "3";
        }
        cout << "36366\n";
    } else {
        for (int i = 0; i < n - 2; ++i) {
            cout << "3";
        }
        cout << "66\n";
    }
    
}
//36366
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
