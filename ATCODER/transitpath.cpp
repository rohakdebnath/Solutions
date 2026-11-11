#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    vector<vector<array<i64, 2>>> adj (n);
    for (i64 i = 0; i < n - 1; ++i) {
        i64 a, b, c; cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    i64 q, k; cin >> q >> k; --k;
    vector<i64> d (n); //d[i] = distance from i to k;
    vector<i64> vis (n);
    auto bfs = [&] (i64 start) {
        queue<i64> q;
        q.push(start);
        while (!q.empty()) {
            i64 top = q.front();
            vis[top] = 1;
            q.pop();
            for (auto [e, w]: adj[top]) {
                if (vis[e]) continue;
                d[e] = d[top] + w;
                q.push(e);
            }
        }
    };
    bfs(k);

    while (q--) {
        i64 a, b; cin >> a >> b;
        --a, --b;
        cout << d[a] + d[b] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


int gcd(int a, int b, int& x, int& y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}
