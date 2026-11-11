#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
    } else {
        vector<int> p (n); p[n - 1] = (n + 1) / 2;
        int c = n;
        for (int i = 1; i < n; i += 2) {
            p[i] = c;
            p[i - 1] = n + 1 - c;
            --c;
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " \n"[i == n - 1];
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
