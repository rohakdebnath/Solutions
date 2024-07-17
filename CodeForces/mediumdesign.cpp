#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> s (n), e (n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> e[i];
    }
    int mx = 0;
    for (int c = 0; c < 2; ++c) {
        vector<pair<int, int>> t;
        if (c == 0) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 1) continue;
                t.push_back({s[i], 1});
                t.push_back({e[i] + 1, -1});
            }
            sort(t.begin(), t.end());
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (e[i] == k) continue;
                t.push_back({e[i], 1});
                t.push_back({s[i] - 1, -1});
            }
            sort(t.begin(), t.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first != b.first ? a.first > b.first : a.second < b.second;
            });
        }
        int m = t.size();
        int x = 0;
        for (int i = 0; i < m; ++i) {
            x += t[i].second;
            mx = max(mx, x);
        }
    }
    cout << mx << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
