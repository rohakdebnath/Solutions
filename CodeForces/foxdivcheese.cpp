#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis (n);
    auto run = [&] (int v) -> vector<int> {
        vector<int> cc;
        auto dfs = [&] (auto&& self, int v) -> void{
            vis[v] = 1;
            cc.push_back(v);
            for (int u: adj[v]) {
                if (!vis[u]) self(self, u);
            }
        };
        dfs(dfs, v);
        return cc;
    };
    vector<vector<vector<int>>> ccl (3);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<int> cc = run(i);
        if (cc.size() > 3) {
            cout << "-1\n";
            return;
        }
        ccl[cc.size() - 1].push_back(cc);
    }
    vector<vector<int>> grp;
    for (int i = 0; i < n / 3; ++i) {
        if (!ccl[2].empty()) {
            auto x = ccl[2].back();
            ccl[2].pop_back();
            grp.push_back(x);
        } else if (!ccl[1].empty()) { 
            auto x = ccl[1].back();
            ccl[1].pop_back();
            if (!ccl[0].empty()) {
                auto y = ccl[0].back();
                ccl[0].pop_back();
                x.insert(x.end(), y.begin(), y.end());
                grp.push_back(x);
            } else {
                cout << "-1\n";
                return;
            }
        } else {
            vector<int> f;
            while (f.size() != 3) {
                if (!ccl[0].empty()) {
                    auto x = ccl[0].back();
                    ccl[0].pop_back();
                    f.push_back(x[0]);
                } else {
                    cout << "-1\n";
                    return;
                }
            }
            grp.push_back(f);
        }
    }
    for (int i = 0; i < n / 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << grp[i][j] + 1 << " \n"[j == 2];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
