#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto dfs = [&] (auto&& self, vector<int>& f, int v, int p) -> void {
        for (int u: adj[v]) {
            if (u == p) continue;
            self(self, f, u, v);
        }
        ++f[a[v]];
    };
    vector<int> f (n);
    dfs(dfs, f, 0, -1);
    int d = count_if(f.begin(), f.end(), [k] (int x) {return x > k;});
    auto ndfs = [&] (auto&& self, vector<int>& f, int v, int p) -> void {
        for (int u: adj[v]) {
            if (u == p) continue;
            self(self, f, u, v);
        }
        ++f[a[v]];
    };

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
