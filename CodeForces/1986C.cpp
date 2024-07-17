#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ind (m); for (int i = 0; i < m; ++i) cin >> ind[i]; sort(ind.begin(), ind.end());
    string c; cin >> c; sort(c.begin(), c.end());
    ind.erase(unique(ind.begin(), ind.end()), ind.end());
    c = c.substr(0, ind.size());
    for (int i = 0; i < ind.size(); ++i) {
        s[ind[i] - 1] = c[i];
    }
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
