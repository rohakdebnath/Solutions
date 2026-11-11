#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> block (n);
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        block[a].push_back(b);
        block[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(block[i].begin(), block[i].end());
    }

    vector<int> vis (n);
    auto dfs = [&] (auto&& self, int v, vector<int>& cc) -> void{
        vis[v] = 1;
        cc.push_back(v);
        for (int u: adj[v]) {
            if (!vis[u]) self(self, u, cc);
        }
    };
    auto count = [&] (vector<int>& a, vector<int>& b) {
        int c = 0;
        for (int i: a) {
            c += (binary_search(b.begin(), b.end(), i));
        }
        return c;
    };
    vector<int> ans (n);
    for (int i = 0; i < n; ++i) {
        vector<int> cc;
        if (!vis[i]) {
            dfs(dfs, i, cc);
        }
        sort(cc.begin(), cc.end());
        for (int c: cc) {
            ans[c] = cc.size() - 1 - count(block[c], cc) - adj[c].size();
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

