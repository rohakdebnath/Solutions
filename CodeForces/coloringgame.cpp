#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    set<int> a, b;
    for (int i = 0; i < n; ++i) b.insert(i + 1);
    vector<int> vis (n), bip (n);
    string s = "Bob";
    auto dfs = [&] (auto&& self, int v, int c) {
        if (vis[v] and bip[v] != c) {
            s = "Alice";
            return;
        }
        if (vis[v]) return;
        bip[v] = c, vis[v] = 1;
        if (c) a.insert(v + 1), b.erase(v + 1);
        for (int u: adj[v]) {
            self(self, u, !c);
        }
    };
    dfs(dfs, 0, 0);
    cout << s << endl;
    if (s == "Alice") {
        for (int _ = 0; _ < n; ++_) {
            cout << "1 2" << endl;
            int i, c; cin >> i >> c;
        }
    } else {
        for (int _ = 0; _ < n; ++_) {
            int u, v; cin >> u >> v;
            if ((u == 1 or v == 1) and a.size()) {
                cout << *a.begin() << ' ' << 1 << endl;
                a.erase(a.begin());
            } else if ((u == 2 or v == 2) and b.size()) {
                cout << *b.begin() << ' ' << 2 << endl;
                b.erase(b.begin());
            } else if (!a.size()) {
                int col = u == 1 ? v : u;
                cout << *b.begin() << ' ' << col << endl;
                b.erase(b.begin());
            } else {
                int col = u == 2 ? v : u;
                cout << *a.begin() << ' ' << col << endl;
                a.erase(a.begin());
            }
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
