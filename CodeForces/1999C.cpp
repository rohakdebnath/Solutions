#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> len;
    for (int i = 1; i < n; ++i) {
        len.push_back(v[i].first - v[i - 1].second);
    }
    len.push_back(m - v.back().second);
    len.push_back(v[0].first);
    sort(len.begin(), len.end());
    cout << (len.back() >= s ? "YES\n": "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
