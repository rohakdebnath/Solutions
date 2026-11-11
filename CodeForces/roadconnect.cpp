#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> f (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; 
        --a, --b;
        ++f[a];
        ++f[b];
    }
    int s = -1;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) s = i;
    }
    cout << n - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        if (i != s) {
            cout << i + 1 << ' ' << s + 1 << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
