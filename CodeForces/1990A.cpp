#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); 
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        --x;
        ++a[x];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
