#include <bits/stdc++.h>
//01, 10
//010101
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n); for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> chn;
    auto dfs = [&] (auto&& self, int v, int p, int s) -> void {
        s = (s << 1 & 0b111) | (s >> 2);
        if (s & 1) a[v] ^= 1;

        if (a[v] ^ b[v]) {
            chn.push_back(v);
            a[v] ^= 1;
            s ^= 1; 
        }

        for (int u: adj[v]) {
            if (u != p) {
                self(self, u, v, s);
            }
        }
    };  
    dfs(dfs, 0, -1, 0);

    cout << chn.size() << '\n';
    for (int i = 0; i < chn.size(); ++i) {
        cout << chn[i] + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
