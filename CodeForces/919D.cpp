#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
    }
    vector<int> in(n);
    for (vector<int>& nodes: adj) {
        for (auto u: nodes) in[u]++;
    }

    queue<int> queue;
    vector<array<int, 26>> dp (n, {0});
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            queue.push(i);
            dp[i][s[i] - 'a'] = 1;    
        }
    }

    vector<int> topo;
    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        topo.push_back(curr);
        for (auto next: adj[curr]) {
            if (--in[next] == 0) queue.push(next);
        }
    }

    if (topo.size() != n) cout << "-1\n";
    else {
        //dp[i][j] = value of path from the first i toponodes which maximises letter j
        for (int i: topo) {
            for (int j: adj[i]) {
                for (int k = 0; k < 26; ++k) {
                    dp[j][k] = max(dp[j][k], dp[i][k] + ((s[j] - 'a') == k));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
