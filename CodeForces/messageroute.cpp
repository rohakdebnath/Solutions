#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    vector<int> p (n, -1);
    vector<int> d (n, inf);
    auto bfs = [&] (int s) {
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int u: adj[top]) {
                if (d[u] == inf) {
                    d[u] = 1 + d[top];
                    p[u] = top;
                    q.push(u);
                }
            }
        }
    };
    bfs(0);
    if (d[n - 1] == inf) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << d[n - 1] + 1 << '\n';
        int last = n - 1;
        vector<int> path;
        while (last != -1) {
            path.push_back(last);
            last = p[last];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] + 1 << " \n"[i == path.size() - 1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
