#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    vector<int> bad (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (c == 2) {
            bad[a] = bad[b] = 1;
        }
    }

    vector<int> cand;
    auto dfs = [&] (auto&& self, int v, int p) -> int {
        int ans = bad[v];
        for (int u: adj[v]) {
            if (u != p) {
                ans += self(self, u, v);
            }
        }
        if (ans == 1) cand.push_back(v);
        return ans;
    };
    dfs(dfs, 0, -1);
    cout << cand.size() << '\n';
    for (int i = 0; i < cand.size(); ++i) {
        cout << cand[i] + 1 << " \n"[i == cand.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
