#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s; cin >> s;
    vector<int> vis (n);
    array<int, 2> fleaf {}; //frequency of 0 and 1s in leafs
    array<int, 2> quest {}; //frequency of question marks in leafs and non leafs respectively
    auto dfs = [&] (auto&& self, int v) -> void{
        vis[v] = 1;
        bool leaf = true;
        for (int u: adj[v]) {
            if (!vis[u]) {
                self(self, u);
                leaf = false;
            }
        }
        if (leaf) {
            if (s[v] == '?') {
                ++quest[0];
            } else {
                ++fleaf[s[v] - '0'];
            }
        } else if (v and s[v] == '?') ++quest[1];
    };
    dfs(dfs, 0);
    int ans = 0;
    if (s[0] == '?') {
        if (fleaf[0] > fleaf[1]) {
            ans = fleaf[0] + quest[0] / 2;
        } else if (fleaf[1] > fleaf[0]) {
            ans = fleaf[1] + quest[0] / 2;
        } else {
            ans = fleaf[0] + (quest[0] + quest[1] % 2) / 2;
        }
    } else {
        int x = s[0] - '0';
        ans = (quest[0] + 1) / 2 + fleaf[!x];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
