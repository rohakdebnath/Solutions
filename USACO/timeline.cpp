#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    setIO("timeline");
    i64 n, m, c; cin >> n >> m >> c;
    vector<i64> a (n); for (i64 i = 0; i < n; ++i) cin >> a[i];
    vector<i64> d = a;

    vector<vector<pair<i64, i64>>> adj(n);
    for (i64 i = 0; i < c; i++) {
        i64 a, b, w; cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
    }

    vector<i64> in(n);
    for (const vector<pair<i64, i64>> &nodes : adj) {
        for (auto [node, w] : nodes) in[node]++;
    }

    queue<i64> queue;
    for (i64 i = 0; i < n; i++) {
        if (in[i] == 0) queue.push(i);
    }
    vector<i64> topo;
    while (!queue.empty()) {
        i64 curr = queue.front();
        queue.pop();
        topo.push_back(curr);
        for (auto [next, w] : adj[curr]) {
            if (--in[next] == 0) queue.push(next);
        }
    }

    //d[i] = earliest time of event i
    for (i64 i = 0; i < n; ++i) {
        int j = topo[i];
        for (auto[u, w]: adj[j]) {
            d[u] = max(d[u], d[j] + w);
        }
    }
    for (i64 i = 0; i < n; ++i) {
        cout << d[i] << '\n';
    }
    return 0;
}
