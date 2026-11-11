#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n == 0) {
        cout << "" << '\n';
    }
    map<int, int, greater<int>> m; //m[i] = 1-index of first occurance of a prefix with sum i
    m[0] = 0;
    int p = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        p += 2 * (s[i] == '(') - 1;
        if (m.find(p) == m.end()) m[p] = i + 1;
        else ans = max(ans, i + 1 - m[p]);

        while (m.begin() -> first > p) m.erase(m.begin());
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
