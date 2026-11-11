#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int y = count(b.begin(), b.end(), '#');
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != '#') continue;
        if (p > min(26, p + y) % 26) {
            y -= 26 - p;
            p = 0;
        }
        a[i] = char('a' + p);
        p = (p + 1) % 26;
    }
    cout << a << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
