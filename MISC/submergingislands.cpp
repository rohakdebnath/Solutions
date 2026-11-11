#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; 
    while (true) {
        cin >> n >> m;
        if (n + m == 0) return;
        vector adj(n, vector<int> ());
        while (m--) {
            int x, y; cin >> x >> y; --x, --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> up (n, 0), ord(n, 0);
        auto dfs = [&] (auto&& self, int v, int p) -> int {
            int c = 0, cut = 0;
            for (int u: adj[v]) {
                if (!ord[u]) {
                    ord[u] = ord[v] + 1;
                    int x = up[v];
                    cut += self(self, u, v);
                    up[v] += up[u];
                    c += up[v] == x;
                } else if (ord[u] < ord[v]) {
                    ++up[v], --up[u];
                }
            }

            if ((p == -1 and c > 1) or (p >= 0 and c > 0)) ++cut;

            return cut;
        };
        ord[0] = 1;
        cout << dfs(dfs, 0, -1) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
