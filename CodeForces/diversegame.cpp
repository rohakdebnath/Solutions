#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a (n * m); for (int i = 0; i < n * m; ++i) cin >> a[i];
    if (n * m == 1){
        cout << "-1\n";
        return;
    }
    rotate(a.begin(), a.begin() + 2, a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i * m + j] << " \n"[j == m - 1];
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
