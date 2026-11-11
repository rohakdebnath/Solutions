#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    array<vector<pair<int, int>>, 2> edges;

    for (int i = 0; i < m; ++i) {
        int t, x, y; cin >> t >> x >> y;
        edges[t].push_back({x - 1, y - 1});
    }

    vector<vector<int>> adj (n);
    for (int i = 0; i < edges[1].size(); ++i) {
        int a = edges[1][i].first, b = edges[1][i].second;
        adj[a].push_back(b);
    }

    vector<int> in(n);
    for (const vector<int> &nodes : adj) {
        for (auto u: nodes) in[u]++;
    }
    
    queue<int> queue;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) queue.push(i);
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

    if (topo.size() != n) cout << "NO\n";
    else {
        vector<array<int, 2>> fedge;
        for (int i = 0; i < n; ++i) {
            for (int u: adj[i]) {
                fedge.push_back({i + 1, u + 1});
            }
        }
        vector<int> rank (n);
        for (int i = 0; i < n; ++i) {
            rank[topo[i]] = i;

        }
        // for (int i = 0; i < n; ++i) {
        //     cout << rank[i] << " \n"[i == n - 1];
        // }

        for (int i = 0; i < edges[0].size(); ++i) {
            if (rank[edges[0][i].first] > rank[edges[0][i].second]) swap(edges[0][i].first, edges[0][i].second);
            fedge.push_back({edges[0][i].first + 1, edges[0][i].second + 1});
        }

        cout << "YES\n";
        for (auto [u, v]: fedge) {
            cout << u << ' ' << v << '\n';
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
