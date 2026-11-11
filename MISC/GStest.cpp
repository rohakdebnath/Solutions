#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<int>> adj (s.size());
    for (int i = 0; i < n; ++i) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    vector<int> vis (s.size());
    auto run = [&] (int i) {
        vector<int> cc;
        auto dfs = [&] (auto&& self, int v) -> void {
            vis[v] = true;
            cc.push_back(v);
            for (int u: adj[v]) {
                if (!vis[u]) {
                    self(self, u);
                }
            }
        };
        dfs(dfs, i);
        sort(cc.begin(), cc.end());
        return cc;
    };
    for (int i = 0; i < s.size(); ++i) {
        if (vis[i]) continue;
        auto v = run(i);
        string t = "";
        for (int x: v) {
            t += s[x];
        }
        sort(t.begin(), t.end());
        int y = 0;
        for (int x: v) {
            s[x] = t[y++];
        }
    }
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
