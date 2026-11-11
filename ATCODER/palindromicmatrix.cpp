#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> f (26);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            ++f[s[j] - 'a'];
        }
    }
    if (n % 2 == 0 and m % 2 == 0) {
        int m21 = 0, m20 = 0, m40 = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] % 4 == 0) ++m40;
            else if (f[i] % 2 == 0) ++m20;
            else ++m21;
        }
        cout << (m21 <= 0 and m20 <= 0 ? "Yes\n": "No\n");
    } else if (n * m % 2 == 0) {
        int m21 = 0, m20 = 0, m40 = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] % 4 == 0) ++m40;
            else if (f[i] % 2 == 0) ++m20;
            else ++m21;
        }
        cout << (m21 <= 0 and m20 <= (m & 1 ? n: m) / 2 ? "Yes\n": "No\n");
    } else {
        int m21 = 0, m20 = 0, m40 = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] % 4 == 0) ++m40;
            else if (f[i] % 2 == 0) ++m20;
            else ++m21;
        }
        cout << (m21 <= 1 and m20 <= m / 2 + n / 2 ? "Yes\n": "No\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
