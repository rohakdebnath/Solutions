#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> f (26, {0, 0});
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        ++f[c - 'a'].first;
        f[c - 'a'].second = c - 'a';
    }
    sort(f.begin(), f.end(), greater<pair<int, int>>());
    string ans;
    while (f[0].first) {
        for (int i = 0; i < 26; ++i) {
            if (f[i].first) {
                ans += char('a' + f[i].second);
                --f[i].first;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
