#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int od = 0, ev = 0;
    for (int i = 29; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            (a[j] % 2) ? ++od : ++ev;
            if (od * ev != 0) {
                cout << "-1\n";
                return;
            }
            a[j] = abs(a[j] - (1 << i));
        }
    }
    if (a[0] == 1) {
        cout << "31\n";
        for (int i = 29; i >= 0; --i) {
            cout << (1 << i) << ' ';
        }
        cout << "1\n";
    } else {
        cout << "30\n";
        for (int i = 29; i >= 0; --i) {
            cout << (1 << i) << ' ';
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
