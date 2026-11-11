#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> p (n);

    for (int i = 0; i < 2 * n; ++i) {
        string s; cin >> s;
        int x = stoi(s.substr(1));
        p[x - 1][s[0] == '-'] = i;
    }
    vector<vector<int>> adj (n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((max(p[i][0], p[j][0]) < min(p[i][1], p[j][1])) and ((p[i][0] < p[j][0] or p[i][1] > p[j][1]) and (p[i][0] > p[j][0] or p[i][1] < p[j][1]))) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> c (n, -1);
    auto dfs = [&] (auto&& self, int v, int col) -> bool {
        if (c[v] != -1) {
            return c[v] == col;
        }
        c[v] = col;
        int bip = true;
        for (int u: adj[v]) {
            bip &= self(self, u, !col);
        }
        return bip;
    };
    bool bip = 1;
    for (int i = 0; i < n; ++i) {
        if (c[i] == -1) {
            bip &= dfs(dfs, i, 0);
        }
    }
    string s = "GS";
    if (!bip) cout << "*\n";
    else {
        for (int i = 0; i < n; ++i) {
            cout << s[c[i]];
        }
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
